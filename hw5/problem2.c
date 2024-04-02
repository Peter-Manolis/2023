#include <stdio.h>
#include <stdlib.h>
//Hi, my name is Peter Manolis.
//The purpose of this code is to create a 2d pointer array with rows and columns given by a user.
//After the user gives the rows and columns, the 2d array allocates memory
//next teh user enteres elements of the array and it fills the first 2d pointer array
//Next a second 2d pointer array is made of teh same size of hte original array, memory is also allocated.
//A method called process is called. process makes every element of the 2nd new 2d array a square of the original array.
//Proccess calls square, which is another function that calls for an integer and returns the square.
//Next the orignal and processed arrays are printed
//Finally the memory is freed is both memories.



//This method squares a given integer
int square(int n) {
    	return n * n;
}

//procces calls 2 arrays, rows and cols given byn the user, and the square method
void process(int **arr2, int **arr1,int (*func)(int), int row, int col) {
	//puts the square of every number in arr1 int the same location but in arr2
    	for (int i = 0; i < row; i++) {
        	for (int j = 0; j < col; j++) {
            	arr2[i][j] = func(arr1[i][j]);
        	}
    	}	
}

int main() {
	//User enters number of rows and cols
	int row;
    	int col;
    	printf("Enter the number of rows: ");
    	scanf("%d", &row);
    	printf("Enter the number of columns: ");
    	scanf("%d", &col);

	//Allocate memory to first array
    	int **arr1 = malloc(row * sizeof(int *));
    	for (int i = 0; i < row; i++) {
        	arr1[i] = malloc(col * sizeof(int));
    	}

	//User gives elements of the array and are placed in the arr1
    	printf("Enter the elements of the array:\n");
    	for (int i = 0; i < row; i++) {
        	for (int j = 0; j < col; j++) {
            	scanf("%d", &arr1[i][j]);
        	}
    	}

	
	//Allocates memory for second array
    	int **arr2 = malloc(row * sizeof(int *));
    	for (int i = 0; i < row; i++) {
        	arr2[i] = malloc(col * sizeof(int));
    	}

	//Calls process method
    	process(arr2, arr1,square,row,col);

	//prints original array
    	printf("\nOriginal Array:\n");
    	for (int i = 0; i < row; i++) {
        	for (int j = 0; j < col; j++) {
            	printf("%d ", arr1[i][j]);
        	}
        	printf("\n");
    	}

	//prints the processed array
    	printf("\nProcessed Array:\n");
    	for (int i = 0; i < row; i++) {
        	for (int j = 0; j < col; j++) {
            	printf("%d ", arr2[i][j]);
        	}
        	printf("\n");
    	}

	//frees memory in first array
    	for (int i = 0; i < row; i++) {
        	free(arr1[i]);
    	}
    	free(arr1);

	//frees memory in second array
    	for (int i = 0; i < row; i++) {
        	free(arr2[i]);
    	}
    	free(arr2);

    	return 0;
}

