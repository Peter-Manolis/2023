//Hi our names are Peter and Milahd. The purpose of output.c is to contain 2 methods and the Inage struct. The Image struct is used throughout all modules. the 2 methods
//writeImage and freeImage write the array onto the output file after manipulations have been made. And finally the memroy allocated for the  array is freed.
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

//Image struct used in all modules
typedef struct {
        int cols;
        int rows;
        int*** data; // 3D array of pixels
} Image;

// write image to file
void writeImage(Image* image, char* filename) {
	//opens file in write open and checks if its able to be opened
	FILE* file = fopen(filename, "w");
	if (file == NULL) {
		fprintf(stderr, "Error: could not open file '%s'\n", filename);
		exit(1);
	}

	//prints the values onto the output file
	int cols = image->cols;
	int rows= image->rows;
	int maxval = 255;
	fprintf(file, "P3\n%d %d\n%d\n", cols, rows, maxval);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			fprintf(file, "%d %d %d ", image->data[i][j][0], image->data[i][j][1],image->data[i][j][2]);
		}
		fprintf(file, "\n");
	}
	fclose(file);
}
// free memory for image data
void freeImage(Image* image) {
        int cols = image->cols;
        int rows = image->rows;
        for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                        free(image->data[i][j]);
                }
                free(image->data[i]);
        }
        free(image->data);
}

