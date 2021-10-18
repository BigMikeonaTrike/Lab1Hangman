#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// define functions
void welcomePrint(); // wihtout parameters AND no return value
char randomLetter(char wordLetters[6], int temp); // with parameters AND return value
void hangmanPrint(int lives, char wordLetters[6], bool correctGuess = false); // with parameters AND no return value
bool playerGuess(int lives, char goal); // with parameters AND assigned to variable


int main()
{
	//initialize variables
	char wordLetters[6] = { 'y','o','o','b','e', 'e' };
	int livesRemain = 3, temp = 0;
	bool correct = false;
	//game start
	welcomePrint();
	char goalLetter = randomLetter(wordLetters, temp); // selects goal letter
	cout << goalLetter;
	hangmanPrint(livesRemain, wordLetters); // prints hangman
a:												
	correct = playerGuess(livesRemain, goalLetter);
	if (correct == false) {
		livesRemain--;
		cout << "\nIncorrect Guess, Try Again\nlives remaining: " << livesRemain << endl;
	}
	if (livesRemain > 0  && correct == false) { // repeats guess until correct or no lives remain
		goto a; 
	}
	if (correct == true) {
		cout << "\nCorrect Guess, Congratulations!\n";
	}
	else {
		cout << "\nOut Of Lives, You Lose\nBetter Luck Next Time!\n";
	}
	hangmanPrint(livesRemain, wordLetters, correct); // prints final hangman
}

bool playerGuess(int lives, char goal) { // asks & gets users guess, returns whether correct
	char input;
	cout << "\nGuess the missing letter: ";
	cin >> input;
	if (input == goal) {
		return true;
	}
	else {
		return false;
	}
}

void welcomePrint() { // prints outs welcome message and line
	cout << "Welcome to Hangman. This game is to check your spelling skill\n";
	for (int i = 0; i < 62; i++) {
		cout << "=";
	}
	cout << endl;
}

char randomLetter(char wordLetters[6], int temp) { // chooses and removes random letter to be goal
	srand(time(0));
	temp = rand() % 5; 
	char tempLetter = wordLetters[temp]; 
	wordLetters[temp] = '_';
	return tempLetter;
}

void hangmanPrint(int lives, char wordLetters[6], bool correctGuess) { // prints hangman in different states depending on whether game active, player won or player lost
	string wholeBody[2][3] = { {"\\0/", " |", "/ \\"}, {" X", "/|\\", "| |"} }; // stores alive and dead hangman

	cout << "\n  ==============";
	cout << "\n  ||       |";
	if (lives <= 0) { // if game over prints dead state
		for (int i = 0; i < 3; i++) { 
			cout << "\n  ||      " << wholeBody[1][i];
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			cout << "\n  ||      ";
			if (correctGuess == true) { // moves hangman to right for 'Walkman' state else print hanging state
				for (int j = 0; j < 5; j++) {
					cout << "  ";
				}
			}
			cout << wholeBody[0][i];
		}
	}
	cout << "\n  ||===|       |===========| ";
	cout << "\n  ||                       |";
	cout << "\n  ||    '";
	if (lives == 0 || correctGuess == true) { // if game over prints full word without missing letter
		cout << "yoobee";
	}
	else {
		for (int i = 0; i < 6; i++) {
			cout << wordLetters[i];
		}
	}
	cout << "'           |";
	cout << "\n  ||                       |";
}
