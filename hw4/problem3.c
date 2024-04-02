#include<stdio.h>
//The purpose of this code is implement a function inside of another function.
//The performOperation function calls another function using a pointer
//it implemets the add adn subtract methods.
//The code allows the user to choose to subtract or add 2 numbers.
//It is another calculator function

//Function that calls another function
int performOperation(int (*otherFunction)(int, int), int x, int y) {
    int result = otherFunction(x, y);
    printf("Result of the operation is %d\n", result);
    return result;
}
//Addition function
int add (int num1, int num2){
	return num1 + num2;
}
//Subtract function
int subtract(int num1, int num2){
        return num1 - num2;
}
int main (void){
	//Calls add method
	int result1 = performOperation(&add, 5, 3); 
  	//Calls subtract method
	int result2 = performOperation(&subtract, 5, 3); 
  	//Print method
	printf("Result 1: %d\n", result1); 
  	printf("Result 2: %d\n", result2);

}

