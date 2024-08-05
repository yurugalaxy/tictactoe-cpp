#pragma once

#include <array>
#include <iostream>

#include "conversion.hpp"
#include "validation.hpp"

struct TicTacToe
{
  enum Player
  {
    NOUGHTS = 1,
    CROSSES = 2
  };

  struct Position
  {
    int X { 0 };
    int Y { 0 };
  };

  struct History
  {
    int rowTop { 0 };
    int rowMiddle { 0 };
    int rowBottom { 0 };
    int colLeft { 0 };
    int colMiddle { 0 };
    int colRight { 0 };
    int diagonalLeft { 0 };
    int diagonalRight { 0 };
  };
};

class Game
{
 private:
  std::array<std::array<char, 3>, 3> m_board {};
  TicTacToe::Position m_boardPos {};
  TicTacToe::History m_p1History {};
  TicTacToe::History m_p2History {};
  TicTacToe::History* m_histPointer { nullptr };
  TicTacToe::Player m_currentPlayer {};
  bool m_gameOver {};
  int m_winner {};
 public:
 private:
 public:
  Game();

  void init();
  bool boardFull();
  bool validSquare() { return m_board[m_boardPos.X][m_boardPos.Y] == ' '; }
  void getUserInput();
  void addHistory(int square);
  bool winner();
  void takeSquare();
  void switchPlayer();
  bool gameOver() { return m_gameOver; };
};