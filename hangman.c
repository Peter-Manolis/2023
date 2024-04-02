#include<stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define NAME_LENGTH 50
#define SIZE 20
// Hello my name is peter manolis, the purpose of this code is to create a hangman game that is played by two users.
// Step by Step:
// 1. The first step i made a coin toss method that decides which user goes first.
// 2. I make a newLines method that prints 250 new lines so the users can't cheat.
// 3. I made an arrays_equal method that checks if the user got every letter.
// 4. I made a playgame method, this method conducts the entire game
// 5. It asks the users for their secret word
// 6. The other user guesss until they have 6 incorrect guesses or they get it right
// 7. After the first user goes, they flip sides
// 8. After both users go, the score is checked and if they are tied, the game is repeated, if not then the winner is presented.

// coin toss method produces a random number 1 or 2.
char cointoss() {
	 srand(time(NULL));

  	int result = rand() % 2;
	if (result == 0) {
    		return 'h';
  	}	 
	else {
    		return 't';
  	}
}

//Produces 250 new lines
void newlines(){
	int i = 0;
	while (i < 250){
		printf("\n");
		i++;
	}
}

// Checks if the user guessed every letter
bool arrays_equal(char arr1[]) {
	int count= 0;
	for (int i = 0; i < strlen(arr1); i++) {
	    if (arr1[i] == '_'){
		    return false;
		    break;
	    }		
    	}

	return true;
}


//Conducts the game.

int playgame (char coinToss, char playerOneName[NAME_LENGTH], char playerTwoName[NAME_LENGTH]) {
	char secretWord[NAME_LENGTH];
	char playerGuess;
	int playerOneGuess =0;
	int playerTwoGuess =0;
	bool correct = false;
	char showSecretWord[NAME_LENGTH];
	int playerTwoWin = 0;
	int playerOneWin = 0;
	if (coinToss == 'h'){

		printf("%s, enter your secret word:\n", playerOneName);
		scanf("%s", secretWord);
		// Displays under scores for not guessed letters.
		for (int i = 0; i < strlen(secretWord); i++){
			showSecretWord[i] = '_';
		}
		newlines();
		
		// User repeats guessing letteers
		do {
			printf("\n");
			printf("%s, enter a letter: \n", playerTwoName);
	  
			scanf("%c", &playerGuess);
			scanf("%c", &playerGuess);
			
			bool correctGuess = false;

			for (int i = 0; i < strlen(secretWord); i++){
        			if (secretWord[i] == playerGuess){
					showSecretWord[i] = playerGuess;
					correctGuess = true;
				}
				 else if (secretWord[i] == toupper(playerGuess)){
                                        showSecretWord[i] = toupper(playerGuess);
                                        correctGuess = true;
                                }

    			}
			if (correctGuess == false){
				playerTwoGuess = playerTwoGuess + 1;
			}
			printf("Word:");
			for (size_t i = 0; i < SIZE && showSecretWord[i] != '\0'; ++i) {
				printf("%c ", showSecretWord[i]);
			}

			puts("");

			printf("\n");
			
			printf("Incorrect Guesses: %d\n", playerTwoGuess);

			correct = arrays_equal(showSecretWord);
			if (playerTwoGuess == 6){
				printf("\n");
				printf("%s loses!\n", playerTwoName);
				break;
			}
			if (correct == true){
				printf("%s wins!\n", playerTwoName);
				playerTwoWin = playerTwoWin + 1;
			}
			
		}while(correct == false); //Goes until the user gets the word corret
		for (int i = 0; i < strlen(showSecretWord); i++){
                                        showSecretWord[i] = '\0';
                                }

		printf("%s's turn\n", playerTwoName);
		return playerTwoWin;
	}

	// Same thinfs apply in the above if statement, just positoin of names are switched.
	else if (coinToss == 't') {
		
		
		
		printf("%s, enter your secret word:\n", playerTwoName);
		scanf("%s", secretWord);
                char showSecretWord[strlen(secretWord)];
                for (int i = 0; i < strlen(secretWord); i++){
                        showSecretWord[i] = '_';
                }
		
		newlines();
		do {
			printf("\n");
			printf("%s, enter a letter: \n", playerOneName);

                	scanf("%c", &playerGuess);
			scanf("%c", &playerGuess);
			
			bool correctGuess = false;
                	for (int i = 0; i < strlen(secretWord); i++){
                       		if (secretWord[i] == playerGuess){
                                	showSecretWord[i] = playerGuess;
                        		correctGuess = true;
				}
				 else if (secretWord[i] == toupper(playerGuess)){
                                        showSecretWord[i] = toupper(playerGuess);
                                        correctGuess = true;
                                }

                	}
			if (correctGuess == false){
                                playerOneGuess = playerOneGuess + 1;
                        }


			printf("Word:");
			for (size_t i = 0; i < SIZE && showSecretWord[i] != '\0'; ++i) {
                        	printf("%c ", showSecretWord[i]);
                	}

                	puts("");
			
			printf("\n");

                        printf("Incorrect Guesses: %d\n", playerOneGuess);

			correct = arrays_equal(showSecretWord);
			if (playerOneGuess == 6){
                                printf("\n");
                                printf("%s loses!\n", playerOneName);
                        	break;
			}
                        if (correct == true){
				printf("%s wins!\n", playerOneName);
				playerOneWin = playerOneWin + 1;
	
                        }
	

		}while (correct==false);
        	for (int i = 0; i < strlen(showSecretWord); i++){
				showSecretWord[i] = '\0';
	  			}

		printf("%s's turn\n", playerOneName);

		return playerOneWin;
	}


}


int main (void){
	
	// Gets the users name
	char playerOneName[NAME_LENGTH];
        printf("Enter player 1 name: \n");
        scanf("%s", playerOneName);

	char playerTwoName[NAME_LENGTH];
        printf("Enter player 2 name: \n");
        scanf("%s", playerTwoName);
	
	int playerTwoGuessCount;
        int playerOneGuessCount;
	//Decide what user goes first
	char coinToss;
	coinToss = cointoss();
	
	// Runs the game until someone has a higher win total
	do {
		if (coinToss == 'h'){
			printf("Coin toss to decide who goes first...and it’s a heads. %s goes first.\n", playerOneName);
			playerTwoGuessCount = playgame('h', playerOneName, playerTwoName);
			playerOneGuessCount = playgame('t', playerOneName, playerTwoName);

		}	
		else if (coinToss == 't'){

			printf("Coin toss to decide who goes first...and it’s a tails. %s goes first.\n", playerTwoName);
			playerTwoGuessCount = playgame('t', playerOneName, playerTwoName);
			playerOneGuessCount = playgame('h', playerOneName, playerTwoName);
		}
	printf("Score:\n");
	printf("%s: %d\n", playerOneName, playerOneGuessCount);
        printf("%s: %d\n", playerTwoName, playerTwoGuessCount);
	if (playerOneGuessCount == playerTwoGuessCount){
		printf("We have a tie, another round!\n");
	}
		

	} while (playerOneGuessCount == playerTwoGuessCount);
	if (playerOneGuessCount > playerTwoGuessCount){
		printf("%s wins!\n", playerOneName);
	}
	else if (playerTwoGuessCount > playerOneGuessCount){
		printf("%s wins!\n", playerTwoName);
	}

}

