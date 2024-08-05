#include "tictactoe.hpp"

int main()
{
  Game game{};

  while (!game.gameOver())
  {
    game.getUserInput();
    game.takeSquare();
  }
}