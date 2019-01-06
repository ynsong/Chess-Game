//
// Created by Gabriel Gu on 2018-03-27.
//

#ifndef A5_BISHOP_H
#define A5_BISHOP_H
#include "cell.h"
#include "piece.h"
#include <iostream>
#include <string>

class Bishop : public Piece {

public:
    Bishop(int x, int y, bool alive, std::string name);
    void produce_next();
    bool isblock(Cell c);
};


#endif //A5_BISHOP_H
