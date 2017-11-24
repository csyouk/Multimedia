#include <constants.h>
#ifndef CONVERTER_H
#define CONVERTER_H
extern unsigned int RGB32[320*480];
extern unsigned int YUV422[320*480];
int yuv422_to_rgb32(char * , int );
int yuv422_to_rgb32_with_adder(char * , Pixel & , int );
void rgb32_to_yuv422(unsigned int * );
int capture_to_file(const void *, int , char *);

#endif
