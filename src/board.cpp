#include <iostream>

#include "board.hpp"
#include "arrayinfo.hpp"

void Board::update(const CoordPlayer& coord)
{
        m_board[coord[0]][coord[1]] = coord[2];
}

void Board::printBoard()
{
        int count { 1 };
        int row { 1 };
        const int rowTotal { ArrayInfo::rowLength(m_board)};
        const int colTotal { ArrayInfo::colLength(m_board)};

        std::cout << '\n' << "Square " << instance() << ": \n";
        for (auto& arow : m_board)
        {
                int col { 1 };
                for (const auto& acol : arow)
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

bool Board::isValid(const Coordinate& coord)
{
        if (m_board[coord[0]][coord[1]] > 0)
                return false;

        return true;
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