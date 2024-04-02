#include<stdio.h>
//Hi, my name is peter manolis. The purpose of this code is to create an inserstion sort code from a pointer to a 2d array
//First this code creates 2 compare methods.
//Compare1 returns 1 when const int *a is greater then const int *b and -1 when a < b, 0 otherwise.
//Compare2 does the same thing, but returns -1 when a > b and 1 when a < b.
//Compare1 sets the array to be smallest to greatest
//compare2 sets the array to be largest to smallest
//the sort method takes an arr and sorts it using insertion sort.
//This is how the insertion sort works
//1. Starting  with  the  second  element  (element  at  index  1),  compare  it  with  the  first  element
//(element at index 0).
//2. If the second element is smaller, swap the two elements.
//3. Move to the third element (element at index 2) and compare it with the elements to its left
//(elements at indices 1, 0).
//4. If the third element is smaller than an element to its left, swap it with the left element, and
//continue comparing with elements to its left until the correct position is found.
//5. Repeat the above steps for all remaining elements (up to index n-1).
//Finally it prints the array sorted using compare1 and compare2

//Method for smallest to largest insertion sort
int compare1(const int* a, const int* b) {
 //Implement compare method here so that it returns 1 if a  > b, -1 if a < b and 0 otherwise.
	if (*a > *b) {
		return 1;
	}
	else if (*a < *b) {
		return -1;
	}
	else{
	       	return 0;
	}
}


//Method for largest to smallest insertion sort
int compare2(const int* a, const int* b) {
 //Implement compare method here so that it returns -1 if a  > b, 1 if a < b and 0 otherwise.}
	if (*a > *b) {
                return -1;
        }
        else if (*a < *b) {
                return 1;
        }
        else{
                return 0;
        }
}

//Insertion sort method
void sort(int* arr, int size, int (*cmp)(const int*, const int*)) {
	int num;
	//Satrts with second element and is coompared to element to the left
    	for (int i = 1; i < size; i++) {
        	num = arr[i];
        	int j = i - 1;
        	for (j = i-1; j >= 0 && cmp(&arr[j], &num) > 0; j--) {
         	   	//Moves number over if smaller/larger 
			arr[j+1] = arr[j];
        	}
		//replaces the number that was moved
        	arr[j+1] = num;
    }    
}


int main() {
	//given array
    	int arr[] = {3, 5, 1, 4, 2};
    	int size = sizeof(arr) / sizeof(arr[0]);
    	int i;

	//prints array smallest to largest
    	printf("Using compare 1:\n");
    	sort(arr, size, compare1);
    	for (i = 0; i < size; i++) {
        	printf("%d ", arr[i]);
   	}
    	printf("\n");


	//prints array largest to smallest
    	printf("Using compare 2:\n");
    	sort(arr, size, compare2);
    	for (i = 0; i < size; i++) {
        	printf("%d ", arr[i]);
    	}
    	printf("\n");

	return 0;
}
