//This is the header file for the output file. It contains teh Image struct, writeImage, and freeImage
//This file i included in all other files as they need access to the Image struct.


//Image struct
typedef struct {
        int cols;
        int rows;
        int*** data; // 3D array of pixels
} Image;


//Writes image file after manipulations
extern void writeImage(Image* image, char* filename);


//frees space that was made for the array
extern void freeImage(Image* image);
