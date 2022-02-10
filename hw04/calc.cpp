#include <cstdio>
#include <cstring>
#include <cstdint>

#include "calc.h"


bool readFourccName(FILE* fp, char* fourcc) {
    // read fourcc name
    if (!fread(fourcc, sizeof(char), 4, fp))
        return false;
    fourcc[4] = '\0';
    printf("FOURCC: %s\n", fourcc);
    return true;
}


void readFourccSize(FILE* fp, int* size) {
    // read fourcc size
    fread(size, sizeof(int), 1, fp);
}


void readFourccContents(FILE* fp, int size, unsigned char* contents) {
    fread(contents, sizeof(char), size, fp);
}


void parseFmt(unsigned char* contents, unsigned int size, Format* format) {
    format->format = *((uint16_t*) (contents));
    format->nchannels = *((uint16_t*) (contents+2));
    format->rate = *((uint32_t*) (contents+4));
    format->byte_rate = *((uint32_t*) (contents+8));
    format->align = *((uint16_t*) (contents+12));
    format->bits_per_sample = *((uint16_t*) (contents+14));
    // size should be 16, bits_per_sample has offset of 14 
    // and size of 2 bytes, so everything is good
    printf("format: %u\n", format->format);
    printf("nchannels: %u\n", format->nchannels);
    printf("rate: %u\n", format->rate);
    printf("byte rate: %u\n", format->byte_rate);
    printf("align: %u\n", format->align);
    printf("bits_per_sample: %u\n", format->bits_per_sample);
}


void parseData(unsigned char* contents, unsigned int size, const Format* format) {
    // works same as /2 with 8|16 and is faster than division
    unsigned int bytesPerSample = format->bits_per_sample % 7; 
    // iterate over contents and print them
    for (unsigned int offset = 0; offset < size; offset += bytesPerSample) {
        int16_t* byte = (int16_t*) (contents + offset);
        printf("%d", *byte);
        if (format->nchannels == 2) {
            offset += bytesPerSample;
            int16_t* byteC2 = (int16_t*) (contents + offset);
            printf("\t|\t%d", *byteC2);
        }
        printf("\n");
    }
}