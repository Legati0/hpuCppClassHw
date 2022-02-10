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
        } else if (!strncmp(name, "data ", 4)) {
            parseData(contents, size, &fmt);
        } else
            printf("Skipping fourcc chunk '%s'", name);
        delete [] contents;
    }
    fclose(fp);
    return 0;
}