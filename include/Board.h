#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <random>
#include "Piece.h"
#include "Bishop.h"
#include "Rook.h"

class Board {
    public:
        Board();
        ~Board();
        void Initial();
        void Display() const;
        bool moveRook();
        Piece* getRook() const;
        bool Simulate();
        bool rookTake(std::pair<int,int> target, std::pair<int,int> pos, std::pair<int,int> new_pos, int size) const;
        bool bishopTake(Bishop*, Piece* target) const;
        
    private:
        Piece* _board[8][8];
        Rook* _rook;
        Bishop* _bishop;
};

#endif // BOARD_H