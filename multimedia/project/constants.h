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

#define MAX_UINT (unsigned int)(1<<31)

namespace APP_CONFIG{
    extern unsigned int index;
    extern unsigned int last;
    extern const unsigned int first;
}

enum IMG_INDEX{IMG_1, IMG_2, IMG_3, IMG_4};


#endif // CONSTANTS_H
