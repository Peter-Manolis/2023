//This is the header file for input.c, as you can tell it only contains allocateImage and readImage.

//allocates space fot the image
extern void allocateImage(Image* image);

//reads the input file and makes it into an array.
extern void readImage(Image* image, char* filename);
