#include "game.hpp"

int Game::play()
{
        if (playerPtr->isHuman())
                board.update(
                        playerPtr->playerTurn(
                        board, playerPtr->ID()));
        else
                board.update(
                        playerPtr->computerTurn(
                        board, *opponentPtr, playerPtr->ID()));
        board.printBoard();

        playerPtr->isWinner();

        board.isFull();

        int next { playerPtr->squareToPlay() };

        return next;
}