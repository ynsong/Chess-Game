//
// Created by Gabriel Gu on 2018-03-27.
//

#ifndef A5_KNIGHT_H
#define A5_KNIGHT_H


#include "cell.h"
#include "piece.h"
#include <iostream>
#include <string>

class Knight : public Piece {

public:
    Knight(int x, int y, bool alive, std::string name, Board *b);
    void produce_next();
    bool isblock(Cell c);
};

#endif //A5_KNIGHT_H
