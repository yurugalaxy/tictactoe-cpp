#include <iostream>

#include "board.hpp"
#include "conversion.hpp"
#include "arrayinfo.hpp"

void Board::printBoard()
{
        int count { 1 };
        int row { 1 };
        const int rowTotal { ArrayInfo::rowLength(m_board)};
        const int colTotal { ArrayInfo::colLength(m_board)};

        std::cout << '\n';
        for (auto& arow : m_board)
        {
                int col { 1 };
                for (auto& acol : arow)
                {
                        switch (acol)
                        {
                        case 1:
                                { std::cout << 'x'; break; }
                        case 2:
                                { std::cout << 'o'; break; }
                        default:
                                std::cout << count;
                        }
                        if (col < colTotal)
                                std::cout << " | ";
                        ++col;
                        ++count;
                }
                if (row < rowTotal)
                        std::cout << "\n--+---+--\n";
                ++row;
        }
        std::cout << "\n\n";
}

bool Board::isFull()
{
        for (int i {0}; i < 3; ++i)
        {
                for (int j {0}; j < 3; j++)
                {
                        if (!m_board[i][j])
                                return false;
                }
        }
        std::cout << "Draw!\n";
        return true;
}

bool Board::validSquare(const Coordinate& coord)
{
        if (m_board[coord[0]][coord[1]] > 0)
        {
                std::cout << "That square is taken! Choose another.\n";
                return false;
        }

        return true;
}

bool Board::update(Player* playerPtr, const int square)
{
        const Coordinate coord = Conversion::convert(square);

        if (!validSquare(coord))
                return false;

        playerPtr->addHistory(square);

        m_board[coord[0]][coord[1]] = playerPtr->ID();
        printBoard();
        return true;
}

bool Board::isWinner(Player* playerPtr)
{
        if (isFull())
                return true;

        for (const int &e : playerPtr->history())
        {
                if (e == 3)
                        return true;
        }
        return false;
}
