#include <stdio.h>
#include <converter.h>
#include <constants.h>
#include <fcntl.h>              /* low-level i/o */
#include <unistd.h>
#include <errno.h>
unsigned int RGB32[320*480];
unsigned int YUV422[320*480];

int yuv422_to_rgb32(char * arr, int ratio)
{
    int i, j;
    int wp = 0;
    unsigned int rgb8888;
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

            rgb8888 = (0xff<<24) | R<<16 | G<<8 | B;
            RGB32[wp++] = rgb8888;
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

            rgb8888 = (0xff<<24) | R<<16 | G<<8 | B;
            RGB32[wp++] = rgb8888;
        }
    }
    return 0;
}


int yuv422_to_rgb32_with_adder(char * arr, Pixel & p, int ratio)
{
    int i, j;
    int wp = 0;
    unsigned int rgb888;
    unsigned int yuv422;
    int R, G, B, A;
    A = 0xff;
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

            R = Y + 1.4075 * (V - 128) + (p.data >> 16 & 0xff);
            if(R>255) R=255;
            if(R<0) R=0;
            G = Y - 3455 * (U - 128)/10000 - (7169 * (V - 128)/10000) + (p.data >> 8 & 0xff);
            if(G>255) G=255;
            if(G<0) G=0;
            B = Y + 17790 * (U - 128)/10000 + (p.data & 0xff);
            if(B>255) B=255;
            if(B<0) B=0;
            A = (p.data >> 24 & 0xff);
            if(A>255) A=255;
            if(A<0) A = 0;
//            if(R<0 || R>255 || G<0 || G>255 || B<0 || B>255) printf("RGB=%d,%d,%d, YUV=%d,%d,%d\n", R, B, B, Y, U, V);

            rgb888 = A<<24 | R<<16 | G<<8 | B;
            RGB32[wp++] = rgb888;
            Y = (yuv422>>16)&0xff;

            R = Y + 1.4075 * (V - 128) + (p.data >> 16 & 0xff);
            if(R>255) R=255;
            if(R<0) R=0;
            G = Y - 3455 * (U - 128)/10000 - (7169 * (V - 128)/10000) + (p.data >> 8 & 0xff);
            if(G>255) G=255;
            if(G<0) G=0;
            B = Y + 17790 * (U - 128)/10000 + (p.data & 0xff);
            if(B>255) B=255;
            if(B<0) B=0;
            A = (p.data >> 24 & 0xff);
            if(A>255) A=255;
            if(A<0) A = 0;
//            if(R<0 || R>255 || G<0 || G>255 || B<0 || B>255) printf("RGB=%d,%d,%d, YUV=%d,%d,%d\n", R, B, B, Y, U, V);

            rgb888 = A<<24 | R<<16 | G<<8 | B;
            RGB32[wp++] = rgb888;
        }
    }

    return 0;
}


void rgb32_to_yuv422(unsigned int * rgb32)
{
    int i, j;
    int wp = 0;
    unsigned int rgb888;
    unsigned int yuv422;
    int R, G, B;
    unsigned char Y, U, V;

    for(i=0; i<480; i++)
    {
        for(j=0; j<320; j++)
        {
            rgb888 = *(unsigned int *)(rgb32+i*320+j);
            R = ((rgb888) >> 16 & 0xff);
            G = ((rgb888) >> 8  & 0xff);
            B = ((rgb888) >> 0  & 0xff);

            Y = R *  0.299 + G *  0.587 + B *  0.114;
            U = R * -0.147 + G * -0.289 + B *  0.436;
            V = R *  0.615 + G * -0.515 + B * -0.100;

            yuv422 = (((unsigned int)V) <<24)| (((unsigned int)Y)<<16) | (((unsigned int)U)<<8) | (Y);
            YUV422[wp++] = yuv422;
        }
    }

}


int capture_to_file(const void *p, int size, char *file_name)
{
    int ret;
    int fd;

    unlink(file_name);
    fd = open(file_name, O_CREAT|O_WRONLY);
    if(fd == ERROR) {
        return ERROR;
    }

    ret = write(fd, p, size);
    if(ret == ERROR) {
        return ERROR;
    }

    fsync(fd);
    close(fd);

    return 0;
}
