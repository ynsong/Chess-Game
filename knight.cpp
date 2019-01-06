//
// Created by Gabriel Gu on 2018-03-27.
//

#include "knight.h"
#include "piece.h"
#include "cell.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

Knight::Knight(int x, int y, bool alive, std::string name, Board *b) :
        x{x}, y{y}, x_prev{x}, y_prev{y}, alive{alive}, chess_name{name}, b{b} {
    this->produce_next();
}

void Knight::produce_next() {
    for(auto item = next_move.begin(); item != next_move.end(); item++) {
        (*item).clear();
    }
    next_move.clear();
    vector<int> Cell1{x + 2, y - 1};
    vector<int> Cell2{x + 2, y + 1};
    vector<int> Cell3{x - 2, y - 1};
    vector<int> Cell4{x - 2, y + 1};
    vector<int> Cell5{x + 1, y + 2};
    vector<int> Cell6{x + 1, y - 2};
    vector<int> Cell7{x - 1, y + 2};
    vector<int> Cell8{x - 1, y - 2};

    next_move.emplace_back(Cell1);
    next_move.emplace_back(Cell2);
    next_move.emplace_back(Cell3);
    next_move.emplace_back(Cell4);
    next_move.emplace_back(Cell5);
    next_move.emplace_back(Cell6);
    next_move.emplace_back(Cell7);
    next_move.emplace_back(Cell8);
}

bool isblock(Cell c) { return false; }