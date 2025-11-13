#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <iostream>

class Piece {
public:
    Piece(std::string color, int row, int col);
    virtual ~Piece() {}
    std::pair<std::string,std::string> getPiece() const;
    void setPosition(int row, int col);
    std::pair<int,int> getPosition();

protected:
    int _row, _col;
    std::string _color;
    std::string _role;
};

#endif // PIECE_H