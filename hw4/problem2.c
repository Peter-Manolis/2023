#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
//The purpose of this code is to create 4 different functions. The main point of this function is a calculator. 
//The 4 functions are a addition, difference, multiplication, and division.
//the main function asks the user to pick what operation they want to do
//afte they choose their operation, the result is displayed and then they are asked if they want to do it again.

//Method for addition
int sum(int *a, int *b){
	*a += *b;
	return *a;
}	
//Method for difference
int diff(int* a, int* b){
        *a -= *b;
        return *a;

}
//Method for muliplication
int mult(int* a, int* b){
        *a *= *b;
        return *a;

}
//Method for Division
int divide(int* a, int* b){
        *a /= *b;
        return *a;

}

int main (void) {
	char userChoice;
	//Continues the main method untik the user enter 'Q'
	do {
		printf("Enter the operation you want to perform(‘+’ for Addition,’-’ for Subtraction,’*’ for Multiplication, ‘/’ for Division, Q to quit): \n");
	        scanf(" %c", &userChoice);
		//Ends the code
		if (userChoice == 'Q'){
			printf("Goodbye!\n");
			break;
		}
		int a;
		int b;

		if (userChoice=='+') {
				printf("Enter the operands for this operation :\n");
		                scanf("%d, %d", &a, &b);
				printf("Your output:\n%d\n", sum(&a,&b));
		}
		else if (userChoice=='-'){
				printf("Enter the operands for this operation :\n");
		                scanf("%d, %d", &a, &b);
				printf("Your output:\n%d\n", diff(&a,&b));
		}
		else if (userChoice=='*'){
				printf("Enter the operands for this operation :\n");
               			scanf("%d, %d", &a, &b);
				printf("Your output:\n%d\n", mult(&a,&b));
		}
		else if (userChoice=='/'){
				printf("Enter the operands for this operation :\n");
		                scanf("%d, %d", &a, &b);
				printf("Your output:\n%d\n", divide(&a,&b));
		}

	}while (true);

}
