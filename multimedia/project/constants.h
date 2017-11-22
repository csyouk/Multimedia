#ifndef CONSTANTS_H
#define CONSTANTS_H


#define CAM_PATH "/mnt/nfs/cam"
#define CAM0_PATH "/mnt/nfs/cam/CAM0000"
#define CAM_N_PATH "/mnt/nfs/cam/CAM%04d"
#define CAM_W 640
#define CAM_H 480

#define OPEN_FILE_ERROR "Open File Failed.\n"

#define PAGE_WEIGHT 4

#define NTHUMBNAILS 8

namespace APP_CONFIG{
    extern unsigned int index;
}

enum IMG_INDEX{IMG_1, IMG_2, IMG_3, IMG_4};


#endif // CONSTANTS_H
