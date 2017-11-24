#ifndef CONSTANTS_H
#define CONSTANTS_H


#define CAM_PATH "/mnt/nfs/cam"
#define CAM0_PATH "/mnt/nfs/cam/CAM0000"
#define CAM_N_PATH "/mnt/nfs/cam/CAM%04d"
#define CAM_W 640
#define CAM_H 480

#define OPEN_FILE_ERROR "Open File Failed.\n"

#define PAGE_WIDTH 4

#define NTHUMBNAILS 8

#define SWIPE_THRESHOLD 100
#define COLOR_BASE 50
#define MAX_UINT (unsigned int)(1<<31)

#define ERROR -1

#define	Macro_Set_Bit(dest, position)					((dest) |=  (0x1u<<(position)))
#define	Macro_Clear_Bit(dest, position)					((dest) &= ~(0x1u<<(position)))
#define	Macro_Invert_Bit(dest, position)				((dest) ^=  (0x1u<<(position)))

#define	Macro_Clear_Area(dest, bits, position)			((dest) &= ~(((unsigned)(bits))<<(position)))
#define	Macro_Set_Area(dest, bits, position)			((dest) |=  (((unsigned)(bits))<<(position)))
#define	Macro_Invert_Area(dest, bits, position)			((dest) ^=  (((unsigned)(bits))<<(position)))

#define	Macro_Write_Block(dest, bits, data, position)	((dest) = (((unsigned)(dest)) & ~(((unsigned)(bits))<<(position))) | (((unsigned)(data))<<(position)))
#define Macro_Extract_Area(dest, bits, position)		((((unsigned)(dest))>>(position)) & (bits))

#define Macro_Check_Bit_Set(dest, position)				((((unsigned)(dest))>>(position)) & 0x1)
#define Macro_Check_Bit_Clear(dest, position)			(!((((unsigned)(dest))>>(position)) & 0x1))

namespace APP_CONFIG{
    extern unsigned int index;
    extern unsigned int last;
    extern const unsigned int first;
}

enum IMG_INDEX{IMG_1, IMG_2, IMG_3, IMG_4};

struct Pixel{
    int data; // A, R, G, B
};

#endif // CONSTANTS_H
