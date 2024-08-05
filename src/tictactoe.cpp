#include "tictactoe.hpp"

Game::Game()
{
  m_board = 
    {{
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
  }};

  m_currentPlayer = TicTacToe::Player::NOUGHTS;
  m_histPointer = &m_p1History;
}

void Game::switchPlayer()
{
  if (m_currentPlayer == TicTacToe::Player::NOUGHTS)
  {
    m_histPointer = &m_p2History;
    m_currentPlayer = TicTacToe::Player::CROSSES;
  }
  else
  {
    m_histPointer = &m_p1History;
    m_currentPlayer = TicTacToe::Player::NOUGHTS;
  }

}

void Game::addHistory(const int square)
{
  if (square < 4)
    m_histPointer->rowTop += 1;

  if (square > 3 && square < 7)
    m_histPointer->rowMiddle += 1;

  if (square > 6)
    m_histPointer->rowBottom += 1;

  if (square == 1 || square == 4 || square == 7)
    m_histPointer->colLeft += 1;

  if (square == 2 || square == 5 || square == 8)
    m_histPointer->colMiddle += 1;

  if (square == 3 || square == 6 || square == 9)
    m_histPointer->colRight += 1;

  if (square == 1 || square == 5 || square == 9)
    m_histPointer->diagonalRight += 1;

  if (square == 3 || square == 5 || square == 7)
    m_histPointer->diagonalLeft += 1;
}

bool Game::winner()
{
  if (m_histPointer->rowTop            == 3
      || m_histPointer->rowMiddle      == 3
      || m_histPointer->rowBottom      == 3
      || m_histPointer->colLeft        == 3
      || m_histPointer->colMiddle      == 3
      || m_histPointer->colRight       == 3
      || m_histPointer->diagonalRight  == 3
      || m_histPointer->diagonalLeft   == 3)
    {
      m_gameOver = true;
      m_winner = m_currentPlayer;
      std::cout << "Player " << m_currentPlayer << " wins!\n";
      return true;
    }
  return false;
}

void Game::getUserInput()
{
  while (true)
  {
    std::cout << "It's player " << m_currentPlayer << "'s turn!\n";
    std::cout << "Enter a square to take: ";
    int square {};
    std::cin >> square;

    if (square < 0 || square > 9)
    {
      std::cout << "Please enter a valid square.\n";
      continue;
    }

    if (Validation::clearFailedExtraction())
    {
      std::cout << "Invalid input, try again.\n";
      continue;
    }

    Validation::ignoreLine();
    m_boardPos.X = Conversion::convert(square)[0];
    m_boardPos.Y = Conversion::convert(square)[1];

    if (!validSquare())
    {
      std::cout << "Square taken, choose another.\n";
      continue;
    }
    addHistory(square);
    return;
  }
  return;
}

void Game::takeSquare()
{
  m_board[m_boardPos.X][m_boardPos.Y] = m_currentPlayer;
  std::cout << "Player " << m_currentPlayer << " has taken "
            << m_boardPos.X << ' ' << m_boardPos.Y << '\n';

  winner();
  switchPlayer();
}