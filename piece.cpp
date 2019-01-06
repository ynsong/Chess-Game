//
// Created by Gabriel Gu on 2018-03-27.
//

#include "piece.h"
#include <iostream>
using namespace std;


bool Piece::attack(Cell c) {
    for(auto it = next_move.begin(); it != next_move.end(); it++) {
        if ((*it)[0] == x && (*it)[1] == y) {
            return true;
        }
    }
    return false;
}

bool Piece::is_alive() { return alive; }

string Piece::get_name() { return chess_name; }
