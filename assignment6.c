#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//Hi my name is Peter Manolis. The purpose of this code is to allow the user to manpulate and interact with a txt file.
//Step by Step:
//First I created a search fil method. This method opens up a given file and searches for a given word by the user.
//When the given word is found, it prints the occurences and prints how many times the word occurs.
//Next I created a replaceText method. This method finds a word in a txt file, and replaces it with a given word by the user.
//Finally i encorporated a menu
//The menu asks the user if they want to search, replace, or quit the program. 
//This continues until they quit

//Search method
void searchFile(char* file, char* text){
	//initialize variables
	FILE *fptr;
	int occurrences = 0;
        int lineNumber = 1;
        char lineText[1000];
        char finalLines[1000];

	//Checks for a valid file
	if((fptr = fopen(file, "a+" ))  == NULL)  {
		printf("File could not be opened\n");
	}
	else {
		//Gets the line of text
		while (fgets(lineText, 1000, fptr) != NULL){

			if (strstr(lineText,text) != NULL){
				occurrences++;
			}
		}
		printf("%d occurrence(s) of '%s' in %s:\n",occurrences,text,file);
		
		rewind(fptr);
		while (fgets(lineText, 1000, fptr) != NULL){

			if(strstr(lineText,text) != NULL){
				printf("Line %d: %s", lineNumber, lineText);
				lineNumber++;
			}

		}

	}
}
//Replace ethod
void replaceText(char*file, char* wordToReplace, char* newWord){
	//Etablish variables needed
	FILE *fPtr;
	FILE  *tempfPtr;
	char * wordFind;
	char lineText[1000];
	//create a temp file
	
	//open the file to read mode
	fPtr = fopen(file, "r");
	//check if the file is able to be opened
	if(fPtr == NULL)  {
                printf("File could not be opened\n");
        }

	tempfPtr = fopen("temp.txt", "w");
	//Check the temp file is able to be opened in write mode
	if(tempfPtr== NULL)  {
                printf("File could not be opened\n");
        }
	else {
		//gets the first line in the original file
		while (fgets(lineText, 1000, fPtr) != NULL){
			//Goes to first occurence of the targeted word
			wordFind = strstr(lineText, wordToReplace);
			while (wordFind != NULL){
				//writes the first line of the original file with the new replaced word
				fwrite(lineText, 1, wordFind - lineText, tempfPtr);
            			fwrite(newWord, 1, strlen(newWord), tempfPtr);
				char buffer[1000];
				strcpy(buffer, wordFind + strlen(wordToReplace));
				strcpy(lineText, buffer);
				wordFind = strstr(lineText, wordToReplace);
        		}
			//Writes the new line
        		fwrite(lineText, 1, strlen(lineText), tempfPtr);
		}
			
	}
	fclose(tempfPtr);
	tempfPtr = fopen("temp.txt", "r");
	fPtr = fopen(file,"w");

	// check if the temp file is able to be opened in read mode
	if (tempfPtr == NULL) {
    		printf("Temp file could not be opened\n");
	} 
	else {
    		// read the contents of the temp file and write them to the input file
    		while (fgets(lineText, 1000, tempfPtr) != NULL) {
        		fprintf(fPtr, "%s", lineText);
    		}
	}
    	fclose(tempfPtr);
    	printf("Successfully replaced %s with %s in %s \n", wordToReplace, newWord, file);
}



int main (void){
	//WElcome user
	printf("Welcome to the Search and Replace program!\n");
	
	//Initialize variable
	int userChoice;
	do{ //Loop until th euser quirs
		//display on the menu	
		printf("1. Search\n");
		printf("2. Replace\n");
		printf("3. Exit\n");
		printf("Enter your choice: ");

		scanf("%d", &userChoice);

		//When teh user chooses search
		if (userChoice == 1){
			//Neccesary varibles are established and scanned for search method
			char fileName[1000];
			printf("Enter the file name:\n");
			scanf("%s", fileName);
			char textToFind[1000];
			printf("Enter the text to search for:\n");
			scanf("%s", textToFind);
			//Search method is ran
			searchFile(fileName, textToFind);
		}
		//When the user chooses replace
		else if (userChoice == 2){
			//Neccesary variables are initialized and scamned for replace method
			char fileName[1000];
                        printf("Enter the file name:\n");
                        scanf("%s", fileName);
                        char textToFind[1000];
                        printf("Enter the text to search for:\n");
                        scanf("%s", textToFind);
			char newText[1000];
                        printf("Enter the text to replace it with: \n");
                        scanf("%s", newText);
			//Replace method is ran
			replaceText(fileName,textToFind,newText);
		}
		//When exit is selected
		else if (userChoice == 3){
			//Says goodbye and ends the program
			printf("Exiting program. Goodbye!\n");
			break;
		}

		else {//The user doesnt enter 1, 2 or 3
			printf("Invalid selection, try again \n");
		}
	}while (userChoice != 3);
}
