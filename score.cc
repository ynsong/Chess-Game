#include "score.h"
#include <string>

using namespace std;

const string finalScore = "Final Score:\n";
const string whiteScore = "White: ";
const string blackScore = "Black: "; 

double Score::getWhite() { return white; }
	
double Score::getBlack() { return black; }

	
void Score::setWhite(double score) { white += score; }
	
void Score::setBlack(double score) { black += score; }
	
string Score::printScore() { 
	return finalScore + whiteScore + to_string(white) + "\n" \
		+ blackScore + to_string(black) + "\n";
}