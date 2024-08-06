#include "tictactoe.hpp"
#include "user_interface.hpp"

int main()
{
  Game game{};

  while (!game.gameOver())
  {
    game.update();
    game.draw();
  }
}