#include <iostream>
#include <string>
#include "board.h"
#include "player.h"
#include "score.h"


using namespace std;

//white piece: K, Q, B, R, N, P
//blace piece: k, q, b, r, n, p




int main() {

  string cmd;
  Player whitePlayer;
  Player blackPlayer;
  Score score;
  Board board;
 
  while(true) {
 	cin >> cmd;
  	if(cin.eof()) break;

  	if(cmd == "setup") {
  		while(true) {
  			cin >> cmd;
  			if(cmd == "done") break; //finish set up
	  		if(cmd == "+") { // add piece to the position
	  			char piece; 
	  			string position;
	  			cin >> piece >> position;
	  			//...
	  			cout << board;
	  		}
	  		else if(cmd == "-") { // remove piece from the position
	  			string position;
	  			cin >> position;
	  			//...
	  			cout << board;
	  		}
	  		else if(c == "=") { // makes it colour's turn to go next
	  			string colour; //black or white
	  			cin >> colour;
	  			//...

	  		}
  		}
  	}

  	else if(cmd == "game") {
  		string player; //human, computer[1-4]
  		cin >> player;
  		//...
  		cin >> player;
  		//...

  		cout << board;

  	}

  	else if(cmd == "move") {
  		string position;
  		int x_prev, y_prev, x, y;
  		cin >> position;
  		x_prev = position[0] - 'a';
  		y_prev = position[1] - 1;
  		//check if a pawn need to be promote
  		cin >> position;
  		x = position[0] - 'a';
  		y = position[1] - 1;
  		//move

  		cout << board;
  	}

  	else if(cmd == "resign"){}

  	else {
  		cout << "Bad input!" << endl;
  	}
  }

  cout << score.printScore(); //print final score
  
  
}
 