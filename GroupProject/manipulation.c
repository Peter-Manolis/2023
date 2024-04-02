//Hi out names our Milahd an dPeter, tge point of this module is to contain all possible manipulation functions that the user can select. Each of these chaneg the image in a specific 
//way by using a for loop. There are 10 possible manipulations.


#include<stdio.h>
#include<string.h>
#include"output.h"


//Negate red, loops through image array and subtracts 255 from red value.
void negate_red(Image* image) {
	int cols = image->cols;
	int rows = image->rows;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			image->data[i][j][0] = 255 - image->data[i][j][0];
		}
	}
}
//Negate green, loops through image array and subtracts 255 from green value.
void negate_green(Image* image) {
	int cols= image->cols;
	int rows= image->rows;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			image->data[i][j][1] = 255 - image->data[i][j][1];
		}
	}
}
//Negate blue, loops through image array and subtracts 255 from red value.
void negate_blue(Image* image) {
	int cols= image->cols;
	int rows= image->rows;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			image->data[i][j][2] = 255 - image->data[i][j][2];
		}
	}
}

//flip hoizontal, loops through image array, creates temporary array and copies the values in oppposite positions in the row.
void flip_horizontal(Image* image) {
	int cols= image->cols;
	int rows= image->rows;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols/ 2; j++) {
			int temp[3];
			memcpy(temp, image->data[i][j], sizeof(temp));
			memcpy(image->data[i][j], image->data[i][cols - j - 1], sizeof(temp));
			memcpy(image->data[i][cols - j - 1], temp, sizeof(temp));
		}
	}
}
// Grey scale, takes the average rgb number found in each cell and makes each value equal to the average.
void grey_scale(Image* image) {
	int cols= image->cols;
	int rows= image->rows;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			int sum = image->data[i][j][0] + image->data[i][j][1] + image->data[i][j][2];
			int avg = sum / 3;
			image->data[i][j][0] = avg;
			image->data[i][j][1] = avg;
			image->data[i][j][2] = avg;
		}
	}
}
//flatten red, makes the red value equal to 0 in each cell.
void flatten_red(Image* image) {
	int cols= image->cols;
	int rows= image->rows;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			image->data[i][j][0] = 0;
		}
	}
}
//flatten green, makes the green value equal to 0 in each cell.

void flatten_green(Image* image) {
	int cols= image->cols;
	int rows= image->rows;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			image->data[i][j][1] = 0;
		}
	}
}
//flatten blue, makes the blue value equal to 0 in each cell.

void flatten_blue(Image* image) {
	int cols= image->cols;
	int rows= image->rows;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			image->data[i][j][2] = 0;
		}
	}
}

//Extreme contrast, loops through image array and if the value at cell is greater then 255/2, set it to 255. if not set it to 0.
void extreme_contrast(Image* image) {

    int cols = image->cols;

    int rows = image->rows;

    int channels = 3;

    int maxval = 255;

    int midpoint = maxval / 2;

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {

            for (int k = 0; k < channels; k++) {

                int val = image->data[i][j][k];

                if (val > midpoint) {

                    image->data[i][j][k] = maxval;

                } else {

                    image->data[i][j][k] = 0;

                }

            }

        }

    }

}
