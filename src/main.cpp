#include "tictactoe.hpp"
#include "user_interface.hpp"

int main()
{
  Game game{};

  while (!game.gameOver())
  {
    clear();
    printLogo();
    printBoard(game);
    game.getUserInput();
    game.takeSquare();
  }
  printBoard(game);
}