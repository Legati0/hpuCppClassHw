#ifndef CALC_H
#define CALC_H

#include <cstdio>
#include <cstdint>


struct Format {
    uint16_t format;
    uint16_t nchannels;
    uint32_t rate;
    uint32_t byte_rate;
    uint16_t align;
    uint16_t bits_per_sample;
};


bool readFourccName(FILE* fp, char* fourcc);
void readFourccSize(FILE* fp, int* size);
void readFourccContents(FILE* fp, int size, unsigned char* contents);

void parseFmt(unsigned char* contents, unsigned int size, Format* format);
void parseData(unsigned char* contents, unsigned int size, const Format* format);


#endif  // CALC_H