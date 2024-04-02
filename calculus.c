#include<stdio.h>
//Hello, my name is Peter Manolis. The purpose of this code is help students with calculus by giving practice on derivatives and integrals.
//Step by Step:
//1. The first step of this code is for the user to ener 3 values
//2. The user selects if they want to practice integrals or derivatives
//3.Then the produced derivative or integral is shown to the user
//4. the user enters a X value
//5. A sum is shown that represents the sum that would be added together with the recently given x value
//6.The user is asked if they want to run the program again
//7.If they select yes, then the program runs again, if they select no, the program says goodbye and ends
//
int main (void){
	int repeatProgram = 1;
	//Keeps the program going until the user says no at the end
	do {
		//The 3 numbers are entered
		printf("Enter a, b, and c\n");
		float value1, value2, value3;
		scanf("%f %f %f", &value1, &value2, &value3);
		//Equation is displayed
		printf("Equation entered %.0fx^2 + %.0fx + %.0f\n",value1, value2, value3);
		//Derivative or integral are selected
		printf("What would you like to do?\n");
		printf("1. Derivative\n");
		printf("2. Integral\n");
		int userChoice;
		scanf("%d", &userChoice);
		//Variables
		float xValue;
		float finalSum = 0;

		//If the user selects Derivative
		if (userChoice == 1){
			value1 = value1 * 2;
			printf("The derivative is %.0fx + %.0f\n", value1, value2);
			printf("Enter x\n");
			scanf("%f", &xValue);
			finalSum = (value1 * xValue) + value2;
			printf("The derivative at x = %.0f is %.2f\n", xValue, finalSum);
		}
		//If the user selects integrals
		else if (userChoice == 2){
			value1 = value1/3;
			value2 = value2/2;
			printf("The integral is %.2fx^3 + %.2fx^2 + %.2fx\n",value1,value2,value3);
			printf("Enter x\n");
			scanf("%f", &xValue);
			finalSum = finalSum + (xValue*xValue*xValue*value1);
			finalSum = finalSum + (xValue*xValue*value2);
			finalSum = finalSum + (xValue*value3);
			printf("The inegral at x = %.0f is %.2f\n",xValue,finalSum);	
		}
		printf("Do you want to repeat?\n");
		char repeatChoice;
		scanf("%c", &repeatChoice);
		scanf("%c", &repeatChoice);
		switch (repeatChoice) {
			case 'y':
				repeatProgram = 1;
				break;
			case 'Y':
				repeatProgram = 1;
				break;
			case 'n':
				repeatProgram = 0;
				break;
			case 'N':
				repeatProgram = 0;
				break;
		}


	}while(repeatProgram==1);	
	printf("Good bye!\n");
}

