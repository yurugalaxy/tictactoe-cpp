#include "game.hpp"
#include "player.hpp"

void playGame()
{
        TicTacToe game;
        Player playerOne('x');
        Player playerTwo('o');

        char currentSide { playerOne.GetSide()};
        bool gameOver{};
        char currentPlayer{ 'x' };

        while (!gameOver)
        {
                if (currentPlayer == 'x')
                {
                        game.UpdateBoard(playerOne.TakeTurn(), currentPlayer);
                        gameOver = game.DetermineWinner(currentPlayer);
                        currentPlayer = 'o';
                } else
                {
                        game.UpdateBoard(playerTwo.TakeTurn(), currentPlayer);
                        gameOver = game.DetermineWinner(currentPlayer);
                        currentPlayer = 'x';
                }
                game.PrintBoard();
        }
}

int main()
{
        playGame();
}

