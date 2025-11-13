#include "Piece.h"

Piece::Piece(std::string color, int row, int col) : _color(color), _row(row), _col(col) {}

std::pair<std::string, std::string> Piece::getPiece() const {
    return {_color, _role};
}

void Piece::setPosition(int row, int col) {
    _row = row;
    _col = col;
}

std::pair<int,int> Piece::getPosition() {
    return {_row, _col};
}