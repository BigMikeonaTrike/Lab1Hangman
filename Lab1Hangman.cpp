#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void welcomePrint();
char randomLetter(char wordLetters[6], int temp);
void hangmanPrint(int lives, char wordLetters[6], bool correctGuess = false);
bool playerGuess(int lives, char goal);



int main()
{
	char wordLetters[6] = { 'Y','o','o','b','e', 'e' };
	int livesRemain = 3, temp = 0;
	bool correct = false;
	welcomePrint();
	char goalLetter = randomLetter(wordLetters, temp);
	cout << goalLetter;
	hangmanPrint(livesRemain, wordLetters);
a:
	correct = playerGuess(livesRemain, goalLetter);
	if (correct == false) {
		livesRemain--;
		cout << "\nIncorrect Guess, Try Again\nlives remaining: " << livesRemain << endl;
	}
	if (livesRemain > 0  && correct == false) {
		goto a;
	}
	if (correct == true) {
		cout << "\nCorrect Guess, Congratulations!\n";
	}
	else {
		cout << "\nOut Of Lives, You Lose\nBetter Luck Next Time!\n";
	}
	hangmanPrint(livesRemain, wordLetters, correct);
}

bool playerGuess(int lives, char goal) {
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

void welcomePrint() { // without parameters
	cout << "Welcome to Hangman. This game is to check your spelling skill\n";
	for (int i = 0; i < 62; i++) {
		cout << "=";
	}
	cout << endl;
}

char randomLetter(char wordLetters[6], int temp) {
	srand(time(0));
	temp = rand() % 5; 
	char tempLetter = wordLetters[temp]; 
	wordLetters[temp] = '_';
	return tempLetter;
}

void hangmanPrint(int lives, char wordLetters[6], bool correctGuess) { // with parameters
	string wholeBody[2][3] = { {"\\0/", " |", "/ \\"}, {" X", "/|\\", "| |"} };

	cout << "\n  ==============";
	cout << "\n  ||       |";
	if (lives <= 0) {
		for (int i = 0; i < 3; i++) {
			cout << "\n  ||      " << wholeBody[1][i];
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			cout << "\n  ||      ";
			if (correctGuess == true) {
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
	if (lives == 0) {
		cout << "Yoobee";
	}
	else {
		for (int i = 0; i < 6; i++) {
			cout << wordLetters[i];
		}
	}
	cout << "'           |";
	cout << "\n  ||                       |";
}
