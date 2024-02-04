#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

char getMove(){
	int move;
	srand(time(NULL));
	move = rand() % 3;
	
	if (move == 0) {
		return 's';
	}
	else if (move == 1) {
		return 'p';
	}
	else return 'r';

}

int getResult(char computerMove, char playerMove) {
	if (computerMove == playerMove) {
		return 0;
	}
	if (computerMove == 'r' && playerMove == 'p') {
		return 1;
	}
	if (computerMove == 'r' && playerMove == 's') {
		return -1;
	}
	if (computerMove == 'p' && playerMove == 'r') {
		return -1;
	}
	if (computerMove == 'p' && playerMove=='s'){
		return 1;
	}
	if (computerMove == 's' && playerMove == 'r') {
		return 1;
	}
	if (computerMove == 's' && playerMove == 'p') {
		return -1;
	}
	return 0;
}

int main() {
	char playerMove;
	cout << "Welcome! This is a rock-paper-scissors game. Enter 'r' for Rock, enter 'p' for Paper and enter 's' for Scissors.";

	while (1) {
		cin >> playerMove;
		if (playerMove == 'p' || playerMove == 'r' || playerMove == 's') {
			break;
		}
		else {
			cout << "Please try again."; //Error!
		}
	}

	char computerMove = getMove();
	int result = getResult(computerMove, playerMove);

	if (result == 0) {
		cout << "Draw!";
	}
	else if (result == 1) {
		cout << "Congratulations! You win.";
	}
	else {
		cout << "You lose. Computer won the game.";
	}

	cout << "Your move:" << playerMove << endl;
	cout << "Computer's move:" << computerMove << endl;

	return 0;
}