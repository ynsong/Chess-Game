//
// Created by Gabriel Gu on 2018-03-27.
//

#include "pawn.h"
#include "piece.h"
#include "cell.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

Pawn::Pawn(int x, int y, bool alive, std::string name) :
        promoted{false}, first_move{false}, x{x}, y{y}, x_prev{x}, y_prev{y},
        alive{alive}, chess_name{name} {
    this->produce_next();
}

void Pawn::produce_next() {
    for(auto item = next_move.begin(); item != next_move.end(); item++) {
        (*item).clear();
    }
    next_move.clear();
    if (first_move == false) { //update first_move
        if (x_prev != x || y_prev != y) first_move = true;
    }
    if (first_move == false) {
        vector<int> Cell1{x, y + 2};
        next_move.emplace_back(Cell1);
    }
    vector<int> Cell2{x, y + 1};
}

bool Pawn::get_promoted() { return promoted; }

void Pawn::set_promoted() { promoted = !promoted; }

bool Pawn::get_FirstMove() { return first_move; }

void Pawn::set_FirstMove() { first_move = !first_move; }

bool Pawn::isblock(Cell c) {
    for (auto i = next_move.begin(); i != next_move.end(); i++) {
        if (b->check_occupied((*i)[0], (*i)[1]) == true) return true;
    }
    return false;
}