#include "Board.h"

Board::Board() {
    for(int r = 0; r < 8; r++){
        for (int c = 0; c < 8; c++){
            _board[r][c] = nullptr;
        }
    }
}

Board::~Board() {
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            delete _board[r][c];
        }
    }
}

void Board::Initial() {
    _rook = new Rook("B", 7, 7);
    _bishop = new Bishop("W", 5, 2);

    _board[7][7] = _rook;
    _board[5][2] = _bishop;
}

void Board::Display() const {
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            if (_board[r][c] != nullptr) {
                std::cout << _board[r][c]->getPiece().first << _board[r][c]->getPiece().second << " ";
            }
            else {
                std::cout << ".  ";
            }
        }
        std::cout << std::endl;
    }
}

int wrapIndex(int idx, int size) {
    return ((idx % size) + size) % size;
}

bool Board::moveRook(){
    std::pair<int,int> b_pos = _bishop->getPosition();
    std::pair<int,int> r_pos = _rook->getPosition();
    std::pair<int,int> move = _rook->generateMove();
    std::pair<int,int> new_pos = r_pos;
    int size = 8;

    std::cout << std::endl;
    if (move.first == 0){ // move row
        std::cout << "coin: heads (up)";
        new_pos.first = wrapIndex((r_pos.first-move.second), size);
    } else { // move col
        std::cout << "coin: tails (right)";
        new_pos.second = (r_pos.second+move.second)%size;
    }
    std::cout << "\ndice sum: " << move.second << " squares\n";
    std::cout << "rooks position: " << char(new_pos.second+97) << (8-new_pos.first) << std::endl;

    _board[new_pos.first][new_pos.second] = _rook;
    if(move.second != size)
        _board[r_pos.first][r_pos.second] = nullptr;

    _rook->setPosition(new_pos.first, new_pos.second);

    // check black win condition
    if(rookTake(b_pos, r_pos, move, size)) {
        return true;
    }

    // std::cout << "(" << r_pos.first << " " << r_pos.second << ")" << std::endl;
    // std::cout << "(" << new_pos.first << " " << new_pos.second << ")" << std::endl;
    // std::cout << move.first << " " << move.second << std::endl;
    return false;
}

Piece* Board::getRook() const {
    return _rook;
}

bool Board::Simulate() { // true is black win, else white win 
    Initial();
    for (int i = 0; i < 15; i++) {
        Display();
        if(moveRook()) { 
            Display();
            return true;
        }
        if(bishopTake(_bishop, _rook)){ // check white win condition
            Display();
            return false;
        }
    }
    Display();
    return true;
}

bool Board::rookTake(std::pair<int,int> target_pos, std::pair<int,int> pos, std::pair<int,int> move, int size) const{
    if (target_pos.second == pos.second && move.first == 0){ // rook and bishop same col and rook is moving row
        for (int i = 1; i <= move.second; i++) {
            if(wrapIndex((pos.first-i), size) == target_pos.first){
                return true;
            }
        }
    } else if (target_pos.first == pos.first && move.first == 1){ // rook and bishop same row and rook is moving col
        for (int i = 1; i <= move.second; i++) {
            if((pos.second+i)%size == target_pos.second){
                return true;
            }
        }
    }

    return false;
}

bool Board::bishopTake(Bishop* bishop, Piece* target) const {
    auto moves = bishop->validMoves();

    if(moves.find(target->getPosition()) != moves.end()) {
        return true;
    }

    return false;
}