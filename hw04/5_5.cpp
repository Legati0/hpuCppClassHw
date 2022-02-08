#include <cstdio>
#include <cstring>
#include <cstdint>
#include "calc.h"


int main() {
    FILE* fp = fopen("./example.wav", "rb");
    //FILE* fp = fopen("./CantinaBand3.wav", "rb");
    //FILE* fp = fopen("./StarWars3.wav", "rb");
    //FILE* fp = fopen("./Wav_868kb.wav", "rb");
    fseek(fp, 12, SEEK_SET);    // skip RIFF size WAVE


    unsigned char* fmtContents;

    char name[5]; 
    readFourccName(fp, name);

    // get data from format chunk
    Format fmt;
    if (!strncmp(name, "fmt ", 4)) {
        unsigned int size = -1;
        fmtContents = readFourccContents(fp, &size);
        parseFmt(fmtContents, size, &fmt);
    } else {
        printf("fmt should be first chunk\n");
        return 1;
    }
    if (*fmt.format != 1) {
        printf("format != 1, stopping\n");
        return 2;
    }
    readFourccName(fp, name);
    //TODO skip other fourcc chunks?

    // as fmtContents is on the heap, the pointers of fmt are still valid

    // get data from data chunk
    unsigned char* dataContents;
    if (!strncmp(name, "data", 4)) {
        unsigned int size = -1;
        dataContents = readFourccContents(fp, &size);
        parseData(dataContents, size, &fmt); // print data
    } else {
        printf("data should be next chunk\n");
        // delete before exit
        delete [] fmtContents;
        fmtContents = nullptr;
        return 1;
    }

    // delete before exit
    delete [] fmtContents;
    delete [] dataContents;
    fmtContents = nullptr;
    dataContents = nullptr;

    fclose(fp);
    return 0;
}