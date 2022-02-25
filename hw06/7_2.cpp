#include <cstdio>
#include <cstring>
#include <cstdint>
#include <portaudio.h>
#include "calc.h"


// if it doesn't work, just try again
int main() {

    // file stuff
    FILE* fp = fopen("./example.wav", "rb");
    fseek(fp, 12, SEEK_SET);    // skip RIFF size WAVE


    // setup PA
    PaStreamParameters outputParameters;
    PaStream *stream;
    PaError err;
    err = Pa_Initialize();
    if( err != paNoError ) goto error;

    outputParameters.device = Pa_GetDefaultOutputDevice(); 
    if (outputParameters.device == paNoDevice) {
      fprintf(stderr,"Error: No default output device.\n");
      goto error;
    }


    unsigned char* contents;

    char name[5]; 
    Format fmt;

    while(readFourccName(fp, name)) {
        int size = 0;
        readFourccSize(fp, &size);
        contents = new unsigned char[size];
        readFourccContents(fp, size, contents);

        if (!strncmp(name, "fmt ", 4)) {
            parseFmt(contents, size, &fmt);
            // set parameters with fmt (one could just pass outputParameters, but lazy)
            outputParameters.channelCount = fmt.nchannels;
            outputParameters.sampleFormat = paInt16;
            outputParameters.suggestedLatency = 0.050; 
            outputParameters.hostApiSpecificStreamInfo = NULL;

        } else if (!strncmp(name, "data", 4)) {
            // play audio
            //printf("%d\n", fmt.rate);
            err = Pa_OpenStream(
                &stream,
                NULL, // no input
                &outputParameters,
                fmt.rate,
                size,
                paClipOff,      // we won't output out of range samples so don't bother clipping them
                NULL, // no callback, use blocking API
                NULL ); // no callback, so no callback userData
            if( err != paNoError ) goto error;
            
            err = Pa_StartStream(stream);
            if( err != paNoError ) goto error;

            err = Pa_WriteStream( stream, contents, size );
            if( err != paNoError ) goto error;


            err = Pa_StopStream( stream );
            if( err != paNoError ) goto error;
            Pa_Sleep( 1000 );

        } else
            printf("Skipping fourcc chunk '%s'", name);

        delete [] contents;
    }

    err = Pa_CloseStream( stream );
    if( err != paNoError ) goto error;

    fclose(fp);
    Pa_Terminate();

    return err;

error:
    fprintf( stderr, "An error occured while using the portaudio stream\n" );
    fprintf( stderr, "Error number: %d\n", err );
    fprintf( stderr, "Error message: %s\n", Pa_GetErrorText( err ) );
	// Print more information about the error.
	if( err == paUnanticipatedHostError )
	{
		const PaHostErrorInfo *hostErrorInfo = Pa_GetLastHostErrorInfo();
		fprintf( stderr, "Host API error = #%ld, hostApiType = %d\n", hostErrorInfo->errorCode, hostErrorInfo->hostApiType );
		fprintf( stderr, "Host API error = %s\n", hostErrorInfo->errorText );
	}
    fclose(fp);
    Pa_Terminate();
    return err;
}