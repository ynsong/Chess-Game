//
// Created by Gabriel Gu on 2018-03-27.
//

#include "king.h"
#include "piece.h"
#include "cell.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

King::King(int x, int y, bool alive, std::string name) :
        first_move{false}, x{x}, y{y}, x_prev{x}, y_prev{y}, alive{alive}, chess_name{name} {
    this->produce_next();
}

void King::produce_next() {
    for(auto item = next_move.begin(); item != next_move.end(); item++) {
        (*item).clear();
    }
    next_move.clear();
    if (first_move == false) {
        if (x_prev != x || y_prev != y) first_move = true;
    }
    vector<int> Cell1{x - 1, y - 1};
    vector<int> Cell2{x - 1, y};
    vector<int> Cell3{x - 1, y + 1};
    vector<int> Cell4{x, y - 1};
    vector<int> Cell5{x, y + 1};
    vector<int> Cell6{x + 1, y - 1};
    vector<int> Cell7{x + 1, y};
    vector<int> Cell8{x + 1, y + 1};

    next_move.emplace_back(Cell1);
    next_move.emplace_back(Cell2);
    next_move.emplace_back(Cell3);
    next_move.emplace_back(Cell4);
    next_move.emplace_back(Cell5);
    next_move.emplace_back(Cell6);
    next_move.emplace_back(Cell7);
    next_move.emplace_back(Cell8);
}

bool King::get_FirstMove() { return first_move; }

void King::set_FirstMove() { first_move = !first_move; }

bool King::isblock(Cell c) {
    for (auto i = next_move.begin(); i != next_move.end(); i++) {
        if (b->check_occupied((*i)[0], (*i)[1]) == true) return true;
    }
    return false;
}