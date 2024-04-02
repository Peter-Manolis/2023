//Hello, the purpose of this code is to make a Book structure that acts like a library. The books in the library can be manipulated by the user.
//Step by Step:
//1. First i made a menu for the user to navigate through. It welcomes the user to the library and asks them what they want to do
//2. I created a view method. This method is used in all other methods. the view mehtod checks if a book exists based on the ISBN
//and returns the index if it does, and -1 otherwise.
//3. I made a addBook method. This method asks the user to enter a ISBN, if it exists, then it asks the quantity of books the user ones to add.
//If it doesnt exists, it asks the user to enter all fields of the Book struct
//4. I made a removeBook method. This method asks the user to enter a ISBN, if it exists, hte book is removed. Otherwise it tells the user the book does not exist
//5. I made an updateBook method. This method allows the user to change any feature to the book. They enter the change if they want one and -1 if they dont want to change that field.
//6. I maed a viewBook method. This method diplasy all information abot the book, based on the ISBN entered by the user. tells the user if the book doesnt exist
//7. I made a loadBooks method. This method imports all books from library.txt into a Book array. It is done at the start of the code.
//8. I made a saveBooks method. This method saves any changes to books and adds any books to library.txt based on changes made by the user.
//9. The user can make as many changed they want in the menu until theyselect exit, which ends the code. 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define MAX_LENGTH 1000


//Book struct 
struct Book {
	//Fields of the struct
	int ISBN;
	char Title[MAX_LENGTH];
	char Author[MAX_LENGTH];
	char Publisher[MAX_LENGTH];
	int Year;
	float Price;
	int Quantity;
};
//initialize all methods
int view ();
void addBook();
void removeBook();
void updateBook();
void viewBook();
void loadBooks();
void saveBooks();
//initialize global variables / array of books.
int numOfBooks = 0;
struct Book books[1000];

int main(){
	//initialize variable
	int userChoice;
	//Welcomes the user
	printf("Hello, welcome to the library\n");
	//Loads all books from library.txt to books[]
	loadBooks();
	//Menu repetas until the user select exit
	do {
		//Asks the user what they want to do
		printf("What would you like to do?\n");
		
		printf("1. Add a Book.\n");
		printf("2. Remove a Book.\n");
		printf("3. Update a Book.\n");
		printf("4. View a Book.\n");
		printf("5. Exit\n");
		
		//assigns the users choise to userChoice
		scanf("%d", &userChoice);

		//if they want to add a book
		if (userChoice == 1){
			addBook();
			//Saves changes made
			saveBooks();
			printf("Book added!\n");
		}
		//If they want to remove a book
		else if (userChoice == 2){
			removeBook();
			//Saves changes made
			saveBooks();
			printf("Book removed!\n");
		}

		//if they want to update a book
		else if (userChoice == 3){
			updateBook();
			//Saves changes made
			saveBooks();
			printf("Book updated!\n");
		}
		//if they want to view a book
		else if (userChoice == 4){
			viewBook();
			//Saves changes made
			saveBooks();

		}
		//if they want to exit the menu / end the code.
		else if (userChoice == 5){
			printf("Goodbye!\n");
			break;
		}

		else {
			printf("Invalid selection, try again.\n");
		}	

	}while(true);		
}


//This function gets the index of the given Book based on its ISBN
int view(){
	//User enter ISBN
	int ISBN;
	printf("Enter the ISBN of the book: \n");
	scanf("%d", &ISBN);
	
	int location = -1;
	//If a matching ISBN is found, location is set to the index
	for(int i =0; i<numOfBooks; i++){
		if (books[i].ISBN == ISBN){
			location = i;
		}
	}
	//returns the index if it exixts, or -1 if it doesnt
	return location;

}

void addBook(){
	
	//user enter am ISBN, if its found it is set to location
	int location = view();
	//Establish variables and allocate memory for pointers
	int newISBN;
	char *newTitle= malloc(1000 * sizeof(char));
	char *newAuthor= malloc(1000 * sizeof(char));
	float newPrice;
	char *newPublisher= malloc(1000 * sizeof(char));
	int newQuant;
	int newYear;
	
	//If the index of the book is found, the user changes only the quantity
	if (location != -1){
		printf("The book exists, enter the Quantity: \n");
		scanf("%d", &newQuant);
		books[location].Quantity += newQuant;
	}

	
	//If the index of the book is not found, the user creates the book.
	else {
		//User enters all fields for a book and the value is given to the Book instance
		printf("Enter the ISBN: \n");
		scanf("%d", &newISBN);
		books[numOfBooks].ISBN = newISBN;
		printf("Enter the title: \n");
		scanf("%s", newTitle);
		strcpy(books[numOfBooks].Title,newTitle);
		printf("Enter the author: \n");
		scanf("%s", newAuthor);
                strcpy(books[numOfBooks].Author,newAuthor);
		printf("Enter the publisher: \n");
		scanf("%s", newPublisher);
                strcpy(books[numOfBooks].Publisher,newPublisher);
		printf("Enter the year: \n");
		scanf("%d", &newYear);
                books[numOfBooks].Year= newYear;
		printf("Enter the price: \n");
		scanf("%f", &newPrice);
                books[numOfBooks].Price= newPrice;
		printf("Enter the quantity\n");
                scanf("%d", &newQuant);
                books[numOfBooks].Quantity= newQuant;
		
		//Number of books goes up 1
		numOfBooks++;

	}
	//frees memory allocated for pointers
	free(newTitle);
        free(newAuthor);
        free(newPublisher);

}

//This method removes books from the array
void removeBook(){

	//user enter am ISBN, if its found it is set to location
	int location = view();



	//If the book exists
	if (location != -1){
		//The index of all members slide down, removing the book.
		for (int i = location; i < numOfBooks - 1; i++){
			books[i] = books[i+1];
		}
		//total books goes down 1
		numOfBooks--;

	}
	//if the book doesnt exist	
	else{ 
		printf("Book doesn’t exist\n");
	}
}

void updateBook(){
	 //user enter am ISBN, if its found it is set to location
	int location = view();
	
	//Established variables and allocated memory for pointers
	int newISBN;
        char *newTitle= malloc(1000 * sizeof(char));
        char *newAuthor= malloc(1000 * sizeof(char));
        float newPrice;
        char *newPublisher= malloc(1000 * sizeof(char));
        int newQuant;
        int newYear;

	//If the book exists, the user is prompted to add new information or -1
	if (location != -1){
 		printf("Book exists \n");
                
		printf("Enter the new title or -1: \n");
                scanf("%s", newTitle);

                printf("Enter the new author or -1: \n");
                scanf("%s", newAuthor);
                
		printf("Enter the new publisher or -1: \n");
                scanf("%s", newPublisher);
               
		printf("Enter the new year or -1: \n");
                scanf("%d", &newYear);
                
                printf("Enter the new price or -1: \n");
                scanf("%f", &newPrice);
           
		printf("Enter the new quantity or -1:\n");
                scanf("%d", &newQuant);

             

		//If the user doesnt enter -1 for a specific field, the change is made to the book
		
		if (atoi(newTitle) != -1){
                	strcpy(books[location].Title, newTitle);
		}
		if (atoi(newAuthor)!= -1){
                	strcpy(books[location].Author, newAuthor);
		}
		if (atoi(newPublisher) != -1){
                	strcpy(books[location].Publisher, newPublisher);
		}
		if (newPrice != -1){
                	books[location].Price = newPrice;
		}
		if (newQuant != -1){
                	books[location].Quantity = newQuant;
		}
		if (newYear != -1){
               		books[location].Year = newYear;
		}
		

	}
	//If the book doesnt exists
	else if (location == -1){
		printf("Book doesn't exists\n");
	}
	//Free memory for pointers
	free(newTitle);
    	free(newAuthor);
    	free(newPublisher);
}

//Diplasy the content of a book
void viewBook(){

	//user enter am ISBN, if its found it is set to location
	int location = view();

	//if the book exists, all of its fields are printed out
	if (location != -1){
		printf("ISBN: %d\n", books[location].ISBN);
		printf("Title: %s\n", books[location].Title);
		printf("Author: %s\n", books[location].Author);
		printf("Publisher: %s\n", books[location].Publisher);
		printf("Year:  %d\n", books[location].Year);
		printf("Price: %f\n", books[location].Price);
		printf("Quantity: %d\n", books[location].Quantity);
	}
	//If the book doesnt exists
	else if (location == -1){
		printf("Book doesn't exists\n");

	}
}
//Loads all books from library.txt to books[].
void loadBooks(){

	//Establish all variables
	char lineBook[1000];
	char *lISBN;
        char *lTitle;
        char *lAuthor;
        char *lPublisher;
        char *lYear;
        char *lPrice;
        char *lQuantity;
	//Open library.txt
	FILE* fPtr = fopen("library.txt", "r");
	if( fPtr == NULL)  {
		printf("File could not be opened\n");
	}

	else {

		//Goes line from line in library.txt 
		//starting at each line the first field is set to the first varible, then the delimiter is searched for
		//once it is found, the next field is given its relative varible. This continues until the line is over and all fields have a variable.
		while (fgets(lineBook, sizeof(lineBook), fPtr) != NULL){
			lISBN  = strtok(lineBook, "~");
			lTitle = strtok(NULL, "~");
			lAuthor = strtok(NULL, "~");
			lPublisher = strtok(NULL, "~");
			lYear = strtok(NULL, "~");
			lPrice = strtok(NULL, "~");
			lQuantity = strtok(NULL, "~");
			
			//Sets the position in books equal to its corresponding text in library.txt
			books[numOfBooks].ISBN = atoi(lISBN);
                 	strcpy(books[numOfBooks].Title, lTitle);
                 	strcpy(books[numOfBooks].Author, lAuthor);
                 	strcpy(books[numOfBooks].Publisher, lPublisher);
                 	books[numOfBooks].Year = atoi(lYear);
                 	books[numOfBooks].Price = atof(lPrice);
                 	books[numOfBooks].Quantity = atoi(lQuantity);
			numOfBooks++;
		}
	}
	//closes library.txt
	fclose(fPtr);
}

//Updates all changes made by the user
void saveBooks(){
	//opens library.txt
	FILE *fPtr = fopen("library.txt", "w");

	//Prints out each book with all its fields seperated by the delimiter "~"
	for(int i = 0; i < numOfBooks; i++) {
        	fprintf(fPtr, "%d~%s~%s~%s~%d~%f~%d\n", books[i].ISBN, books[i].Title, books[i].Author, books[i].Publisher, books[i].Year, books[i].Price, books[i].Quantity);
    	}


	//Closes library.txt
    	fclose(fPtr);
}
