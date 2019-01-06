//
// Created by Gabriel Gu on 2018-03-27.
//

#ifndef A5_PIECE_H
#define A5_PIECE_H
#include <vector>
#include "cell.h"
#include <iostream>
#include "board.h"
 class Piece {
 protected:
     int x;
     int y;
     int x_prev;
     int y_prev;
     bool alive;
     std::string chess_name;
     std::vector<std::vector<int>> next_move;
     Board *b;
     void SetX(int x) { this->x = x; }
     void setY(int y) { this->y = y; }
     void SetX_prev(int x) { this->x_prev = x; }
     void SetY_prev(int y) { this->y_prev = y; }
     void SetAlive() { this->alive = !alive; }
     int getX() { return x; }
     int getY() { return y; }
     int getX_prev() { return x_prev; }
     int getY_prev() { return y_prev; }
     std::vector<std::vector<int>> & getNext_move() { return this->next_move; }
     bool getAlive() { return alive; }
 public:
     virtual void produce_next() = 0;
     bool attack(Cell c);
     bool is_alive();
     std::string get_name();
     virtual bool isblock(Cell c) = 0; //check if there is any cell between c and current piece
 };


// note getNext_move is returning a reference to vector
// note when construct a piece, give its x and y, alive. for x_prev, set it as -1

#endif //A5_PIECE_H
