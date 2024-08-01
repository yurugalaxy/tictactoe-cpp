#include "player.hpp"
#include "board.hpp"

int main()
{

        Board square1{ 1 };
        Board* squarePtr { &square1 };
        Player playerOne { 1, true };
        Player playerTwo { 2, true };
        Player* playerPtr { &playerOne };
        Player* opponentPtr { &playerTwo };
        bool win { false };
        bool currPlayer { false };

        while (true)
        {
                if (playerPtr->isHuman())
                        squarePtr->update(
                                playerPtr->playerTurn(
                                *squarePtr, playerPtr->ID()));
                else
                        squarePtr->update(
                                playerPtr->computerTurn(
                                *squarePtr, *opponentPtr, playerPtr->ID()));
                squarePtr->printBoard();

                if (playerPtr->isWinner())
                        break;

                if (squarePtr->isFull())
                        break;

                squarePtr->printBoard();
                playerPtr = currPlayer ? &playerOne : &playerTwo;
                opponentPtr = currPlayer ? &playerTwo : &playerOne;
                currPlayer = !currPlayer;

        }
}
