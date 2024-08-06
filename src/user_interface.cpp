#include <iostream>
#include "user_interface.hpp"

std::string g_nextMessage{};

std::array<std::string_view, 3> g_X{
    "\x1B[31m  ▚ ▞  \x1B[0m"
  , "\x1B[31m   █   \x1B[0m"
  , "\x1B[31m  ▞ ▚  \x1B[0m"
};

std::array<std::string_view, 3> g_O{
    "\x1B[36m  ▛▔▜  \x1B[0m"
  , "\x1B[36m  ▏ ▕  \x1B[0m"
  , "\x1B[36m  ▙-▟  \x1B[0m"
};

void clear()
{
  // For unix systems
  std::cout << "\x1B[2J\x1B[H";
}

void createMessage(const std::string_view message)
{
  g_nextMessage = message;
}

void appendMessage(const std::string_view message)
{
  g_nextMessage += message;
}

void printMessage()
{
  std::cout << g_nextMessage;
  g_nextMessage = "";
}

void printLogo()
{
  std::cout << " TicTacToe :3\n\n";
}

void printLine(const int i, Game& game)
{
  std::string line {};

  for (int k { 0 }; k < 3; ++k)
  {
    for (int j { 0 }; j < 3; ++j)
    {
      switch (game.board[i][j])
      {
        case TicTacToe::Player::NOUGHTS:
          line += g_O[k];
        break;
        case TicTacToe::Player::CROSSES:
          line += g_X[k];
        break;
        default:
          line += "       ";
      }
      if (j < 2)
        line += "▒";
    }
    std::cout << line << '\n';
    line = "";
  }

  std::cout << '\n';
}

void printSeparator()
{
  std::cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n";
}

void printBoard(Game& game)
{
  printLine(0, game);
  printSeparator();
  printLine(1, game);
  printSeparator();
  printLine(2, game);
}
