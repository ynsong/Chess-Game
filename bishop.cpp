//
// Created by Gabriel Gu on 2018-03-27.
//

#include "bishop.h"
#include "piece.h"
#include "cell.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

Bishop::Bishop(int x, int y, bool alive, std::string name) :
        x{x}, y{y}, x_prev{x}, y_prev{y}, alive{alive}, chess_name{name} {
    this->produce_next();
}

void Bishop::produce_next() {
    for(auto item = next_move.begin(); item != next_move.end(); item++) {
        (*item).clear();
    }
    next_move.clear();
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if (j - i == y - x || j + i == x + y ) {
                vector<int> Cell{i, j};
                next_move.emplace_back(Cell);
            }
        }
    }
}

bool Bishop::isblock(Cell c) {
    vector<vector<int>> to_check;
    if (c.get_x() < x && c.get_y() < y) {
        for (auto it = next_move.begin(); it != next_move.end(); it++) {
            if ((*it)[0] < x && (*it)[1] < y) {
                vector<int> temp{(*it)[0], (*it)[1]};
                to_check.emplace_back(temp);
            }
        }
    } else if (c.get_x() < x && c.get_y() > y) {
        for (auto it = next_move.begin(); it != next_move.end(); it++) {
            if ((*it)[0] < x && (*it)[1] > y) {
                vector<int> temp{(*it)[0], (*it)[1]};
                to_check.emplace_back(temp);
            }
        }
    } else if (c.get_x() > x && c.get_y() < y) {
        for (auto it = next_move.begin(); it != next_move.end(); it++) {
            if ((*it)[0] > x && (*it)[1] < y) {
                vector<int> temp{(*it)[0], (*it)[1]};
                to_check.emplace_back(temp);
            }
        }
    } else if (c.get_x() > x && c.get_y() > y) {
        for (auto it = next_move.begin(); it != next_move.end(); it++) {
            if ((*it)[0] > x && (*it)[1] > y) {
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
