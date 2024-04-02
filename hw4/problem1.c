#include<stdio.h>
#include<string.h>
//The purpose of this code is to follow 15 simple steps givin in the assignment. The code goes over the use of pointers and how they interact with other variavles.
//It goes through assigning values and printing those values and the location of those values. 
int main (void){
	double number1 = 7.3, number2;
	char s1[100], s2[100]; 
	//1.  Declare the variable dPtr to be a pointer to a variable of type double. 
	double *dPtr;
	//2.  Assign the address of variable number1 to pointer variable dPtr. 
	dPtr = &number1;
	//3.  Print the value of the variable pointed to by dPtr to the display. 
	printf("%f\n", *dPtr);
	//4.  Assign the value of the variable pointed to by dPtr to variable number2. 
	number2 = *dPtr;
	//5.  Print the value of number2 to the display. 
	printf("%f\n", number2);
	//6.  Print the address of number1 to the display. 
	printf("%p\n", (void *)&number1);
	//7.  Print the address stored in dPtr to the display. 
	printf("%p\n", (void *)dPtr);
	//8.  Copy the string stored in character array s1 into character array s2. 
	strcpy(s2, s1);
	//9.  Compare the string stored in character array s1 with the string in character array s2, and print the result to the display. 
	if (strcmp(s1, s2) == 0) { 
		printf("Are equal\n"); 
	} 
	else { 
		printf("Not equal\n"); 
	}
	//10. Determine the length of the string stored in character array s1, and print the result to the display.
	int lenOfs1 = strlen(s1); 
	printf("s1 len = %d\n", lenOfs1);
	//11.  Declare the variable ddPtr to be a pointer to a pointer of variable of type double. 
	double **ddPtr;
	//12. Assign the address of variable dPtr to pointer variable ddPtr. 
	ddPtr = &dPtr;
	//13. Print the value of the variable pointed to by ddPtr to the display.
	printf("%f\n", **ddPtr);
	//14. Change the value of number1 using ddPtr. 
	**ddPtr = 3.0;
	number1 = **ddPtr;
	//15. Change the value of dPtr to point to number2 using ddPtr. 
	*dPtr = **ddPtr;
	printf("%f and %f", number1, number2);	
}
