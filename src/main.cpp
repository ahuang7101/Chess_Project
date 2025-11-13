#include <iostream>
#include "Board.h"

int main() {
    Board game;
    if(game.Simulate()) {
        std::cout << "Black Wins!";
    } else{
        std::cout << "White Wins!";
    }
    return 0;
}

/*
g++ src/*.cpp -Iinclude -o main
./main
*/