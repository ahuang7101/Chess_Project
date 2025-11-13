#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"
#include <String>
#include <set>

class Bishop : public Piece {
public:
    Bishop(std::string color, int row, int col);
    ~Bishop() override {}
    std::set<std::pair<int,int>> validMoves();
};

#endif // BISHOP_H