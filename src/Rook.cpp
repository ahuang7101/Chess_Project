#include "Rook.h"

Rook::Rook(std::string color, int row, int col): Piece(color, row, col) {
    _role = "R";
}

std::pair<int,int> Rook::generateMove() const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dir_distrib(0,1);
    std::uniform_int_distribution<> dice_distrib(1,6);

    int dir = dir_distrib(gen);
    int mag = dice_distrib(gen) + dice_distrib(gen);

    return {dir, mag};
}