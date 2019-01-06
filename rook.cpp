//
// Created by Gabriel Gu on 2018-03-27.
//

#include "rook.h"
#include "piece.h"
#include "cell.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

Rook::Rook(int x, int y, bool alive, std::string name) :
        first_move{false}, x{x}, y{y}, x_prev{x}, y_prev{y}, alive{alive}, chess_name{name} {
    this->produce_next();
}

void Rook::produce_next() {
    for(auto item = next_move.begin(); item != next_move.end(); item++) {
        (*item).clear();
    }
    next_move.clear();
    if (first_move == false) {
        if (x_prev != x || y_prev != y) first_move = true;
    }
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if (j == y || i == x) {
                vector<int> Cell{i, j};
                next_move.emplace_back(Cell);
            }
        }
    }
}

bool Rook::get_FirstMove() { return first_move; }

void Rook::set_FirstMove() { first_move = !first_move; }

bool Rook::isblock(Cell c) {
    vector<vector<int>> to_check;
    if (c.get_x() == x && c.get_y() > y) {
        for (auto it = next_move.begin(); it != next_move.end(); it++) {
            if ((*it)[0] == x && (*it)[1] > y) {
                vector<int> temp{(*it)[0], (*it)[1]};
                to_check.emplace_back(temp);
            }
        }
    } else if (c.get_x() == x && c.get_y() < y) {
        for (auto it = next_move.begin(); it != next_move.end(); it++) {
            if ((*it)[0] == x && (*it)[1] < y) {
                vector<int> temp{(*it)[0], (*it)[1]};
                to_check.emplace_back(temp);
            }
        }
    } else if (c.get_x() > x && c.get_y() == y) {
        for (auto it = next_move.begin(); it != next_move.end(); it++) {
            if ((*it)[0] > x && (*it)[1] == y) {
                vector<int> temp{(*it)[0], (*it)[1]};
                to_check.emplace_back(temp);
            }
        }
    } else if (c.get_x() < x && c.get_y() == y) {
        for (auto it = next_move.begin(); it != next_move.end(); it++) {
            if ((*it)[0] > x && (*it)[1] == y) {
                vector<int> temp{(*it)[0], (*it)[1]};
                to_check.emplace_back(temp);
            }
        }
    }
    for(auto i = to_check.begin(); i != to_check.end(); i++) {
        if (b->check_occupied((*i)[0], (*i)[1]) == true) return true;
    }
    return false;
}
