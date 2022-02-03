#ifndef CALC_H
#define CALC_H

#include <cstdio>
#include <cstdint>


struct Format {
    uint16_t* format;
    uint16_t* nchannels;
    uint32_t* rate;
    uint32_t* byte_rate;
    uint16_t* align;
    uint16_t* bits_per_sample;
};

void parseFmt(unsigned char* contents, unsigned int size, Format* format);

void parseData(unsigned char* contents, unsigned int size, Format* format);

unsigned char* readFourccContents(FILE* fp, unsigned int* size);

void readFourccName(FILE* fp, char* fourcc);

#endif  // CALC_H