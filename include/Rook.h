#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"
#include <String>
#include <random>

class Rook : public Piece {
    public:
    Rook(std::string color, int row, int col);
    ~Rook() override {}
    std::pair<int,int> generateMove() const;
    private:

};

#endif // ROOK_H