#include<stdio.h>
#include <stdlib.h>
#include <time.h>
/*Hello, my name is Peter Manolis. The purpose of this code is to have a guessing game that can be played between friends or by yourself.
 * There are 3 difficulties, Easy (0 to 10), Medium (0 to 100), and Hard (0 to 1000).
 * Step by Step:
 * 1. I made a getNumOfPlayers method that returns how many people are playing based on the users input.
 * 2. I make a getDifficultyLevel method that returns what difficulty the player or players are playing on
 * 3. I created 3 methods, the first is playOnePlayerGame. This method loops the same person to guess over and over again until they guess the random number
 * 4. playTwoPlayerGame goes back adn forth between two players as they try to be the fastest to guess the random number
 * 5. playGame method produces random numbers and includes all details gathered from the previous methods
 * 6. Finally these methods are used in the main method to complete the program 
 */


// Gets num of players
int getNumOfPlayers() {
	int numPlayers;
	printf("Welcome to Number Guessing Game by Peter Manolis\n");
	printf("Please enter the number of players (1 or 2): \n");
	scanf("%d",&numPlayers);

	return numPlayers;

}	
// Gets difficulty level
int getDifficultyLevel() {
	printf("Please choose an option: \n");
	printf("Press 0 for instructions\n");
	printf("Press 1 for Easy difficulty (upto 10) \n");
	printf("Press 2 for Medium difficulty (upto 100)\n");
	printf("Press 3 for Hard difficulty (upto 1000) \n");
	printf("Please choose from 0, 1, 2, 3:\n");
	int difficultyLevel;
	scanf("%d",&difficultyLevel);
	
	return difficultyLevel;
}
//One player game
int playOnePlayerGame (int randNumber, int difficultyLevel) {
        int randNumGuessCorrect = 0;
        int playerGuess;
	int numGuesses = 0;
	//loops until the user gets the number correct
        do {
                if (difficultyLevel == 1){
                        printf("Player 1, please enter a number from 0 to 10:\n");
                        scanf("%d", &playerGuess);
                        if (playerGuess < randNumber) {
                                printf("Player 1, your guess is lower than the real answer\n");
                                numGuesses = numGuesses + 1;
                        }
                        else if (playerGuess > randNumber) {
                                printf("Player 1, your guess is higher than the real answer\n");
                                numGuesses = numGuesses + 1;
                        }
                        else if (playerGuess == randNumber){
				numGuesses = numGuesses + 1;
                                printf("Well done, you guessed it in %d tries.\n", numGuesses);
                		randNumGuessCorrect = 1;
			}
		}
		else if (difficultyLevel == 2){
			printf("Player 1, please enter a number from 0 to 100:\n");
                        scanf("%d", &playerGuess);
                        if (playerGuess < randNumber) {
                                printf("Player 1, your guess is lower than the real answer\n");
                                numGuesses = numGuesses + 1;
                        }
                        else if (playerGuess > randNumber) {
                                printf("Player 1, your guess is higher than the real answer\n");
                                numGuesses = numGuesses + 1;
                        }
                        else if (playerGuess == randNumber){
                                numGuesses = numGuesses + 1;
                                printf("Well done, you guessed it in %d tries.\n", numGuesses);
                                randNumGuessCorrect = 1;
                        }

		}
		else if (difficultyLevel == 3){
			printf("Player 1, please enter a number from 0 to 1000:\n");
                        scanf("%d", &playerGuess);
                        if (playerGuess < randNumber) {
                                printf("Player 1, your guess is lower than the real answer\n");
                                numGuesses = numGuesses + 1;
                        }
                        else if (playerGuess > randNumber) {
                                printf("Player 1, your guess is higher than the real answer\n");
                                numGuesses = numGuesses + 1;
                        }
                        else if (playerGuess == randNumber){
                                numGuesses = numGuesses + 1;
                                printf("Well done, you guessed it in %d tries.\n", numGuesses);
                                randNumGuessCorrect = 1;
                        }

		}


        }while (randNumGuessCorrect == 0);
}

// For two player games
int playTwoPlayerGame(int randNumberOne,int randNumberTwo, int difficultyLevel){
        int playerGuess;
        int playerOneNumGuesses = 0;
	int playerTwoNumGuesses = 0;
	int playerOneCorrect = 0;
        int playerTwoCorrect = 0;
	int bothPlayersCorrect = 0;
	//loops until both players get it crrect
	do {
                if (difficultyLevel == 1){
			int playerOneTurn = 1;
			// Player ones turb
			do{
				if (playerOneCorrect == 0){
                     			printf("Player 1, please enter a number from 0 to 10:\n");
                       	 		scanf("%d", &playerGuess);
                       			if (playerGuess < randNumberOne) {
						printf("Player 1, your guess is lower than the real answer\n");
                                		playerOneNumGuesses = playerOneNumGuesses + 1;
                        		}
                      	  		else if (playerGuess > randNumberOne) {
                                		printf("Player 1, your guess is higher than the real answer\n");
                                		playerOneNumGuesses = playerOneNumGuesses + 1;
                        		}
                        		else if (playerGuess == randNumberOne){
                                		playerOneNumGuesses = playerOneNumGuesses + 1;
						printf("Player 1 is right! your number is %d. You did it in %d tries\n", randNumberOne, playerOneNumGuesses);
						bothPlayersCorrect = bothPlayersCorrect + 1;
						playerOneCorrect++;
                       	 		}
				}
				playerOneTurn = 0;
			}while (playerOneTurn == 1);
                	// Player twos turn
			do{
				if (playerTwoCorrect == 0){
                                
					printf("Player 2, please enter a number from 0 to 10:\n");
                                	scanf("%d", &playerGuess);
                                	if (playerGuess < randNumberTwo) {
                                        	printf("Player 2, your guess is lower than the real answer\n");
                                        	playerTwoNumGuesses = playerTwoNumGuesses + 1;
                                	}
                                	else if (playerGuess > randNumberTwo) {
                                        	printf("Player 2, your guess is higher than the real answer\n");
                                        	playerTwoNumGuesses = playerTwoNumGuesses + 1;
                                	}
                                	else if (playerGuess == randNumberTwo){
                                		playerTwoNumGuesses = playerTwoNumGuesses + 1;
						printf("Player 2 is right! your number is %d. You did it in %d tries\n", randNumberTwo, playerTwoNumGuesses);
						bothPlayersCorrect = bothPlayersCorrect + 1;
						playerTwoCorrect++;
                                	}
				}
				playerOneTurn = 1;

                        }while (playerOneTurn == 0);
		}
		else if (difficultyLevel == 2){
                        int playerOneTurn = 1;
                        //Player ones turn
			do{
                                if (playerOneCorrect == 0){
                                        printf("Player 1, please enter a number from 0 to 100:\n");
                                        scanf("%d", &playerGuess);
                                        if (playerGuess < randNumberOne) {
                                                printf("Player 1, your guess is lower than the real answer\n");
                                                playerOneNumGuesses = playerOneNumGuesses + 1;
                                        }
                                        else if (playerGuess > randNumberOne) {
                                                printf("Player 1, your guess is higher than the real answer\n");
                                                playerOneNumGuesses = playerOneNumGuesses + 1;
                                        }
                                        else if (playerGuess == randNumberOne){
                                                playerOneNumGuesses = playerOneNumGuesses + 1;
                                                printf("Player 1 is right! your number is %d. You did it in %d tries\n", randNumberOne, playerOneNumGuesses);
                                                bothPlayersCorrect = bothPlayersCorrect + 1;
                                                playerOneCorrect++;
                                        }
                                }
                                playerOneTurn = 0;
                        }while (playerOneTurn == 1);
                        //Player twos turn
			do{
                                if (playerTwoCorrect == 0){

                                        printf("Player 2, please enter a number from 0 to 100:\n");
                                        scanf("%d", &playerGuess);
                                        if (playerGuess < randNumberTwo) {
                                                printf("Player 2, your guess is lower than the real answer\n");
                                                playerTwoNumGuesses = playerTwoNumGuesses + 1;
                                        }
                                        else if (playerGuess > randNumberTwo) {
                                                printf("Player 2, your guess is higher than the real answer\n");
                                                playerTwoNumGuesses = playerTwoNumGuesses + 1;
                                        }
                                        else if (playerGuess == randNumberTwo){
                                                playerTwoNumGuesses = playerTwoNumGuesses + 1;
                                                printf("Player 2 is right! your number is %d. You did it in %d tries\n", randNumberTwo, playerTwoNumGuesses);
                                                bothPlayersCorrect = bothPlayersCorrect + 1;
                                                playerTwoCorrect++;
                                        }
                                }
                                playerOneTurn = 1;

                        }while (playerOneTurn == 0);
                }
		else if (difficultyLevel == 3){
                        int playerOneTurn = 1;
                        //Player ones turn
			do{
                                if (playerOneCorrect == 0){
                                        printf("Player 1, please enter a number from 0 to 1000:\n");
                                        scanf("%d", &playerGuess);
                                        if (playerGuess < randNumberOne) {
                                                printf("Player 1, your guess is lower than the real answer\n");
                                                playerOneNumGuesses = playerOneNumGuesses + 1;
                                        }
                                        else if (playerGuess > randNumberOne) {
                                                printf("Player 1, your guess is higher than the real answer\n");
                                                playerOneNumGuesses = playerOneNumGuesses + 1;
                                        }
                                        else if (playerGuess == randNumberOne){
                                                playerOneNumGuesses = playerOneNumGuesses + 1;
                                                printf("Player 1 is right! your number is %d. You did it in %d tries\n", randNumberOne, playerOneNumGuesses);
                                                bothPlayersCorrect = bothPlayersCorrect + 1;
                                                playerOneCorrect++;
                                        }
                                }
                                playerOneTurn = 0;
                        }while (playerOneTurn == 1);
                        //Player Twos turn
			do{
                                if (playerTwoCorrect == 0){

                                        printf("Player 2, please enter a number from 0 to 1000:\n");
                                        scanf("%d", &playerGuess);
                                        if (playerGuess < randNumberTwo) {
                                                printf("Player 2, your guess is lower than the real answer\n");
                                                playerTwoNumGuesses = playerTwoNumGuesses + 1;
                                        }
                                        else if (playerGuess > randNumberTwo) {
                                                printf("Player 2, your guess is higher than the real answer\n");
                                                playerTwoNumGuesses = playerTwoNumGuesses + 1;
                                        }
                                        else if (playerGuess == randNumberTwo){
                                                playerTwoNumGuesses = playerTwoNumGuesses + 1;
                                                printf("Player 2 is right! your number is %d. You did it in %d tries\n", randNumberTwo, playerTwoNumGuesses);
                                                bothPlayersCorrect = bothPlayersCorrect + 1;
                                                playerTwoCorrect++;
                                        }
                                }
                                playerOneTurn = 1;

                        }while (playerOneTurn == 0);
                }


	}while (bothPlayersCorrect < 2); //Ends when both players have guessed correctly
	printf("***************************************************************\n");
	//Produces who won the game
	if (playerOneNumGuesses < playerTwoNumGuesses){
		printf("Player 1 won!!!\n");
	}
	else if(playerOneNumGuesses > playerTwoNumGuesses){
		printf("Player 2 won!!!\n");
	}
	else {
		printf("Player 1 and Player 2 tied\n");
	}
        printf("***************************************************************\n");

}
//Play game function conducts the game
int playGame(int numOfPlayers, int difficultyLevel) {
	int randNumber;
	int randNumberOne;
	int randNumberTwo;
	srand(time(NULL));
	if (difficultyLevel == 0) {
		printf("Your goal is to guess the target number in as little tries as possible.\n");
		printf("The game will tell you if the guess is too high or too low\n");
		printf("Good luck\n");
	}
	else if (difficultyLevel == 1) {
		printf("I am thinking of a number 0 to 10\n");
		randNumber = rand() % 11;
		if (numOfPlayers == 1){
			playOnePlayerGame(randNumber, 1);
		}
		else if (numOfPlayers == 2) {
			randNumberOne = rand() % 11;
			randNumberTwo = rand() % 11;
			playTwoPlayerGame(randNumberOne,randNumberTwo,1);
		}
	}
	else if (difficultyLevel == 2) {
		printf("I am thinking of a number from 0 to 100\n"); 
		randNumber = rand() % 101;

		if (numOfPlayers == 1){
                        playOnePlayerGame(randNumber, 2);
                }
		  else if (numOfPlayers == 2) {
                        randNumberOne = rand() % 101;
                        randNumberTwo = rand() % 101;
			
                        playTwoPlayerGame(randNumberOne,randNumberTwo,1);
                }

	}
	else if (difficultyLevel == 3) {
		printf("I am thinking of a number from 0 to 1000\n"); 
		randNumber = rand() % 1001;
		if (numOfPlayers == 1){
                        playOnePlayerGame(randNumber, 3);
                }
		else if (numOfPlayers == 2) {
                        randNumberOne = rand() % 1001;
                        randNumberTwo = rand() % 1001;
                        playTwoPlayerGame(randNumberOne,randNumberTwo,1);
                }
	}
	
}

//main method only contains two variables and 3 methods.
int main (void) {
	int noofplayers = getNumOfPlayers(); 
  	int difficultylevel = getDifficultyLevel(); 
  	playGame(noofplayers, difficultylevel); 
}
