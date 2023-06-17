#include <iostream>
#include <cstdlib>
#include <cctype>
using namespace std;
int main(){
	//declare variables
	string name;
	int gamePoints = 100;
	int firstInt = -1; //left non-displayed num
	int secondInt = -1; //right
	enum action{DisplayLeft = 1, DisplayRight = 2, Guess = 3, Change = 4, Exit = 5}; //options
	int choice; //choice of option in "switch" code
	bool Left; //displayed left num
	bool Right; //^right
	int numGuess;
	srand(time(NULL)); //seeding the random number
	int numL, numR; //random numbers

	//print user information
	cout << "+----------------------------------------------------------+" << endl;
	cout << "|                Computer Science and Engineering          |" << endl;
	cout << "|                 CSCE 1030 - Computer Science I           |" << endl;
	cout << "|    							    |" << endl;
	cout << "|            Timothy Porr tjp0154 timothyporr@my.unt.edu   |" << endl;
	cout << "+----------------------------------------------------------+" << endl;

	cout << endl;
	cout << endl;

	//get user name and convert to proper format
	cout << "Enter your name: ";
	getline(cin, name);
	name[0] = toupper(name[0]); //first letter uppercase
	for (int i = 1; i < name.size(); i++) {
		if (isspace(name[i])) { //if there is a space the next character will become uppercase
			name[i + 1] = toupper(name[i + 1]);
		}
		if (!isspace(name[i - 1])) { //lowercase everything else
			name[i] = tolower(name[i]);
		}
		if (!isalpha(name[i]) && !isspace(name[i])) {
			cout << "Enter only letters please" << endl;
			cin >> name;
		}
	}

	//welcome user and start game
	cout << "Hello " << name << endl << endl;
	do {
		//generate random numbers until the left is greater than right
		numL = (rand() % 100) + 100;
		numR = (rand() % 100) + 100;
	} while (numL < numR);

	//game loop
	do {
		cout << firstInt << "       " << secondInt << endl; //-1 will show for both sides until it is displayed  by user
		cout << "1. Display Left Number" << endl;
		cout << "2. Display Right Number" << endl;
		cout << "3. Guess a number in between" << endl;
		cout << "4. Change numbers" << endl;
		cout << "5. Exit" << endl;
		cout << endl;
		cout << "What will you choose? ";
		cin >> choice;

		switch (choice) {
		case 1: //display left
			if (!Left) {
				cout << "The left number is:  " << numL << endl;
				Left = true;
			}
			else {
				cout << "You already dsiplayed the left number" << endl;
			}
			break;
		case 2: //displays right; CANNOT DISPLAY BOTH AT THE SAME TIME!
			if (!Right) {
				cout << "The right number is:  " << numR << endl;
				Right = true;
			}
			else {
				cout << "You have already displayed the right number." << endl;
			}
			break;
		case 3: //guess;  if no number displayed user can win or lose 5 pts, if 1 number is displayed user can win 1 pt or lose 10pts
			cout << "What is your guess? " << endl;
			cin >> numGuess;
			if ((!Right || !Left) && numGuess == numL || numGuess == numR) {
				cout << "You guessed the number!" << endl;
				gamePoints += 5;
			}
			else if ((Right || Left) && numGuess == numL || numGuess == numR) {
				cout << "You guessed the number!" << endl;
				gamePoints += 1;
			}
			else if ((!Right || !Left) && numGuess != numL || numGuess != numR) {
				cout << "Incorrect guess!" << endl;
				gamePoints -= 5;
			}
			else if ((Right || Left) && numGuess != numL || numGuess != numR) {
				cout << "Incorrect guess!" << endl;
				gamePoints -= 10;
			}
			break;
		case 4: //resets and changes the random numbers
			do {
				//will generate random numbers until the left is greater than right
				numL = (rand() % 100) + 100;
				numR = (rand() % 100) + 100;
			} while (numL < numR);
			Left = false;
			Right = false;
			cout << "New numbers generated!" << endl;
			break;
		case 5: //exit and/or unkown input
			cout << "Thank you for playing " << name << " !" << endl;
		}
	} while (choice != 5 && gamePoints > 0);

	//display final score
	cout << endl;
	cout << "Your final points balance = " << gamePoints << endl;
	cout << endl;
	return 0;
}
