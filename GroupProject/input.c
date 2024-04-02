//Hi our names are Peter and Milahd. The purpose of this input module is to contain 2 methods that relate to the file input by the user. IT takes the file given by the user and
//produces an array. IT also allocates memory for that array.

#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"output.h"

//Uses 3 mallocs to allocate space for the array produced from the image.
void allocateImage(Image* image) {
	int cols = image->cols;
	int rows = image->rows;
	image->data = (int***)malloc(sizeof(int**) * rows);
	for (int i = 0; i < rows; i++) {
		image->data[i] = (int**)malloc(sizeof(int*) * cols);
		for (int j = 0; j < cols; j++) {
			image->data[i][j] = (int*)malloc(sizeof(int) * 3);
		}
	}
}

//reads the image file that the user inputs and converts it into an array
void readImage(Image* image, char* filename) {

	//opens file and checks if its able to be opened
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		fprintf(stderr, "Error: could not open file '%s'\n", filename);
		exit(1);
	}
	//scan the first 3 standard numbers in file
	char magic[3];
	int cols, rows, maxval;
	fscanf(file, "%2s\n%d %d\n%d\n", magic, &cols, &rows, &maxval);
	if (strcmp(magic, "P3") != 0) {
		fprintf(stderr, "Error: file '%s' is not a PPM image\n", filename);
		exit(1);
	}
	image->cols = cols;
	image->rows = rows;
	allocateImage(image);

	//produce the array based on the image file.
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			fscanf(file, "%d %d %d", &image->data[i][j][0], &image->data[i][j][1],&image->data[i][j][2]);
		}
	}
	fclose(file);
}
