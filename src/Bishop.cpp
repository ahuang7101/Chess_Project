#include "Bishop.h"

Bishop::Bishop(std::string color, int row, int col): Piece(color, row, col) {
    _role = "B";
}

std::set<std::pair<int,int>> Bishop::validMoves() {
    std::set<std::pair<int,int>> valid_moves;
    
    int directions[4][2] = {
        {-1, -1},
        {-1, +1},
        {+1, -1},
        {+1, +1}
    };
    for (auto& dir : directions) {
        int r = _row + dir[0];
        int c = _col + dir[1];

        while (r >= 0 && r < 8 && c >= 0 && c < 8) {
            valid_moves.insert({r,c});
            r += dir[0];
            c += dir[1];
        }
    }


    return valid_moves;
}