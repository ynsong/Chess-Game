//
// Created by Gabriel Gu on 2018-03-27.
//

#ifndef A5_PAWN_H
#define A5_PAWN_H
#include "cell.h"
#include "piece.h"
#include <iostream>
#include <string>

class Pawn : Piece {
    int promoted;//true means this piece is promoted, no point of using this piece
    int first_move; //used to see if adding (x y+2) into the next move vector
public:
    Pawn(int x, int y, bool alive, std::string name);
    void produce_next();
    bool get_promoted();
    void set_promoted();
    bool get_FirstMove();
    void set_FirstMove();
    bool isblock(Cell c);
};


#endif //A5_PAWN_H
