#include <stdio.h>
#include <converter.h>
unsigned int rgb32[640*480];
int convert_to_rgb32(char * arr, int ratio)
{
    int i, j;
    int wp = 0;
    unsigned int rgb888;
    unsigned int yuv422;
    int R, G, B;
    unsigned char Y, U, V;
    int inc = 1 << (ratio-1);

    for(i=0; i<480; i+=inc)
    {
        for(j=0; j<320; j+=inc)
        {
            yuv422 = *(unsigned int *)(arr+i*640*2+j*4);

            U = (yuv422>>8)&0xff;
            V = (yuv422>>24)&0xff;


            Y = yuv422&0xff;

            R = Y + 1.4075 * (V - 128);
            if(R>255) R=255;
            if(R<0) R=0;
            G = Y - 3455 * (U - 128)/10000 - (7169 * (V - 128)/10000);
            if(G>255) G=255;
            if(G<0) G=0;
            B = Y + 17790 * (U - 128)/10000;
            if(B>255) B=255;
            if(B<0) B=0;
            if(R<0 || R>255 || G<0 || G>255 || B<0 || B>255) printf("RGB=%d,%d,%d, YUV=%d,%d,%d\n", R, B, B, Y, U, V);

            rgb888 = (0xff<<24) | R<<16 | G<<8 | B;
            rgb32[wp++] = rgb888;
            Y = (yuv422>>16)&0xff;

            R = Y + 1.4075 * (V - 128);
            if(R>255) R=255;
            if(R<0) R=0;
            G = Y - 3455 * (U - 128)/10000 - (7169 * (V - 128)/10000);
            if(G>255) G=255;
            if(G<0) G=0;
            B = Y + 17790 * (U - 128)/10000;
            if(B>255) B=255;
            if(B<0) B=0;
            if(R<0 || R>255 || G<0 || G>255 || B<0 || B>255) printf("RGB=%d,%d,%d, YUV=%d,%d,%d\n", R, B, B, Y, U, V);

            rgb888 = (0xff<<24) | R<<16 | G<<8 | B;
            rgb32[wp++] = rgb888;
        }
    }

    return 0;
}
