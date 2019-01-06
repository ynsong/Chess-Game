//
// Created by Gabriel Gu on 2018-03-27.
//

#ifndef A5_KING_H
#define A5_KING_H
#include "cell.h"
#include "piece.h"
#include <iostream>
#include <string>

class King : public Piece {
    bool first_move;
public:
    King(int x, int y, bool alive, std::string name);
    void produce_next();
    bool get_FirstMove();
    void set_FirstMove();
    bool isblock(Cell c) {

};


#endif //A5_KING_H
