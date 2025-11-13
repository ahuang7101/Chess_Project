# ROOK VS BISHOP
A simple project written in c++ to simulate a simple chess game variant.

## To run the project
in the root folder run in terminal:

g++ -std=c++17 src/*.cpp -Iinclude -o main
./main

# Programming Language C++
- I have a personal preference for c++ because it is the main language I used for my academic studies so I have a better initial idea for how to approach this prompt. I also have done similar OOP projects in c++.
- c++ is a compiled language and which offer faster performance than interpreted ones such as python.

# Solution 
## Piece, Bishop, Rook Classes
- I first created a base class "Piece" which will be inherited by the two "Rook" and "Bishop" Pieces to reduce redundancy in the code. This also offers the opportunity to easily expand on the project by adding more inherited classes for the other chess pieces. 

- The Rook class handles the generation of a move using two random devices in the function generateMove(). A rounded random number from (0-1) will represent the heads and tails respectively. Two rounded random number from (1-6) will represent the two dice. The sum of the dice and the coins value will be return for the Board to handle repositioning.

- The Bishop class will calculate which squares that is a viable move which will be used by Board class to check if there is a win condition.

## Board Class
- For simulating a board the best choice for me is the 2d array of pointers to Piece. The index of the array will point to a Piece if a piece exist in that position. Most of logic relating to the game will be handle in this class, such as checking if the game should end.

# Other Details
## Small notes
I abbreviated the colors and roles of the chess pieces for a nice visual display.
- WB = White Bishop
- BR = Black Rook

I left in some code that is unused in the simulation that was mostly used for testing. Also a lot of the code is messy and can be touch up upon as I got a better idea of how I wanted to complete the task the longer I worked on it, but that would require a lot of time that I don't have.

- I don't display the individual dice rolls and display only the sum for convienence 

## How the Rook captures the Bishop
The Rook uses O(1) by setting the new position with index. If the Rook is is a position that is possible to generate dice roll and direction that could capture the Bishop an O(n) operation is used to check each square between the current and next position. I like this alternative to checking every square the Rook passes through as it slightly more efficient practially. I honestly struggled a little bit on how I wanted to design this part and the solution I came up with ended up being complex like checking for the two piece being in the same row and the the rook moving columns. 😵‍💫

## How the Bishop Captures the Rook
- The Bishop can generate a set of positions (row, col) that is diagonal to it with member function validMoves(). The Board Class uses the set of positions to check if a pieces position can be found in the set of valid moves from the Bishop.

- For a simple project such as this with only two piece to keep track of, it would have been easier to hard code the positions diagonal to the set Bishop, but I prefer to design the project as dynamic as possible for personal preference and possible future expansions. The Bishop can be in any possition and the set of valid moves should change accordingly. However, this complicates the code a little bit and unecessarily adds computational time for a project such as this.