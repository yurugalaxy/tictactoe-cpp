#include <iostream>

#include "game.hpp"

int main()
{
        Game game1 { 1 };
        Game game2 { 2 };
        Game game3 { 3 };
        Game game4 { 4 };
        Game game5 { 5 };
        Game game6 { 6 };
        Game game7 { 7 };
        Game game8 { 8 };
        Game game9 { 9 };
        Game* currPtr { &game1 };
        int currInstance { 1 };
        int next { 1 };
        int overPlayer { false };

        while (true)
                {

                switch (next)
                {
                        case 1:
                                currPtr = &game1;
                                break;
                        case 2:
                                currPtr = &game2;
                                break;
                        case 3:
                                currPtr = &game3;
                                break;
                        case 4:
                                currPtr = &game4;
                                break;
                        case 5:
                                currPtr = &game5;
                                break;
                        case 6:
                                currPtr = &game6;
                                break;
                        case 7:
                                currPtr = &game7;
                                break;
                        case 8:
                                currPtr = &game8;
                                break;
                        case 9:
                                currPtr = &game9;
                                break;
                }

        std::cout << '\n' << "Square " << next << ": \n";

        overPlayer = !overPlayer;

        currPtr->playerPtr =
                overPlayer ? &currPtr->playerOne : &currPtr->playerTwo;

        currPtr->opponentPtr =
                overPlayer ? &currPtr->playerTwo : &currPtr->playerOne;

        currPtr->board.printBoard();
        next = currPtr->play();

        currPtr->playerPtr =
                overPlayer ? &currPtr->playerOne : &currPtr->playerTwo;

        currPtr->opponentPtr =
                overPlayer ? &currPtr->playerTwo : &currPtr->playerOne;

        currPtr->currPlayer =
                overPlayer;
                }
}
