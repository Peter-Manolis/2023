//Hi my name is Peter and my partner is Milahd. This is the main file that creates a menu and akss the user to input what changes they want to make to their file.
//It also asks the user to input the file name and output file name.it includes manipulation.h, input.h, and output.h and uses the methods from those.

#include <stdio.h>
#include <stdlib.h>

//include  the other modules
#include "output.h"
#include "input.h"
#include "manipulation.h"

int main() {
	//initialize varibles 
	char input[100];
	char output[100];
	int choice;
	Image image;
	
	//introduce and say hello to the users
	printf("Portable Pixmap (PPM) Image Editor\n");
	
	//User enters the input file
	printf("Enter name of image file: ");
	scanf("%s", input);
	
	//check if the input file is a valid file.
	if (fopen(input, "r") == NULL) {
		printf("Error reading image file.\n");
		return 1;
	}

	//User emters the output file.
	printf("Enter name of output file: ");
	scanf("%s", output);

	//Establish more variables
	char more_operations = 'y';
	char change_input_file;
	char change_output_file;
	
	//While loops that continues until the user is done making manipulations
	while (more_operations == 'y' || more_operations == 'Y') {
		//reads the image entered by the user
		readImage(&image, input);
		//Main menu 
		printf("Here are your choices:\n");
		printf("[0] exit\n");
		printf("[1] convert to greyscale\n");
		printf("[2] flip horizontally\n");
		printf("[3] negative of red\n");
		printf("[4] negative of green\n");
		printf("[5] negative of blue\n");
		printf("[6] just the reds\n");
		printf("[7] just the greens\n");
		printf("[8] just the blues\n");
		printf("[9] extreme contrast\n");
		printf("Enter choice: ");
		//Scans the users input
		scanf("%d", &choice);

		//switch case for hwat manipulation the user wants to do
		switch (choice) {

			//Exit
			case 0:
				printf("Exiting program...\n");
				return 0;
			//Grey scale
			case 1:
				grey_scale(&image);
				writeImage(&image,output);
				printf("%s created with effect, 'convert to greyscale.'\n", output);
				break;
			//flip horizontal
			case 2:
				flip_horizontal(&image);
				writeImage(&image,output);
				printf("%s created with effect, 'flip horizontally.'\n", output);
				break;
			//Negate red
			case 3:
				negate_red(&image);
				writeImage(&image,output);
				printf("%s created with effect, 'negative of red.'\n", output);
				break;
			//Negate Green
			case 4:
				negate_green(&image);
				writeImage(&image,output);
				printf("%s created with effect, 'negative of green.'\n", output);
				break;
			//Negate Blue
			case 5:
				negate_blue(&image);
				writeImage(&image,output);
				printf("%s created with effect, 'negative of blue.'\n", output);
				break;
			//Flatten red
			case 6:
				flatten_red(&image);
				writeImage(&image,output);
				printf("%s created with effect, 'just the reds.'\n", output);
				break;
			//Flatten green
			case 7:
				flatten_green(&image);
				writeImage(&image,output);
				printf("%s created with effect, 'just the greens.'\n", output);
				break;
			//flatten Blue
			case 8:
				flatten_blue(&image);
				writeImage(&image,output);
				printf("%s created with effect, 'just the blues.'\n", output);
				break;
			//Extreme contrast
			case 9:
				extreme_contrast(&image);
				writeImage(&image, output);
				printf("%s created with effect, 'extreme contrast.'\n", output);
				break;

			//If the users input is invalid
			default:
				printf("Invalid choice.\n");
				break;
		}
		//Checks if the output file is valid.
		if (choice > 0 && choice < 10) {
			if (fopen(output, "r") == NULL) {
				printf("Error writing image file.\n");
				return 1;
			}
		}
		//asks the user if they want to do more operations
		printf("Do you want to do more operations (y or n): ");
		while(1){
			scanf(" %c", &more_operations);

			//If the user wants to do more operations
			if (more_operations == 'y') {
				
				while(1) {
					//asks if they want to chnage the inout file
					printf("Do you want to change input file (y or n):\n");
					scanf(" %c", &change_input_file);
					//changes the name of the input file
					if (change_input_file == 'y'){
						printf("Enter name of image file: \n");
						scanf("%s", input);
						break;
					}
					//break if they dont want to chnage input file
					else if (change_input_file == 'n'){
						break;
					}
				}
				//asks if they want to change the output file
				while(1) {

					 printf("Do you want to change output file (y or n):\n");
					 scanf("%s", &change_output_file);
					 //changes the name of the output file
					 if (change_output_file == 'y'){
						 printf("Enter name of output file: \n");
						 scanf("%s", output);
						 break;
					 }
					 //break if they dont want to chnage the output file
					 else if (change_output_file == 'n'){
						 break;
					 }
				}
				break;
				}
			//When the user doesnt want to do more operations
			else if (more_operations == 'n'){
				printf("Bye Bye! \n");
				//frees allocated mempry 
				freeImage(&image);
			}
			break;
		}	
	}
	//Ends program
	printf("Exiting program...\n");
	return 0;
}

