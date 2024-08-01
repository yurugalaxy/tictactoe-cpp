// #pragma once
//
// #include <array>
//
// class Board
// {
//         using Array2D = std::array<std::array<int, 3>, 3>;
//         using Coordinate = std::array<int, 2>;
//         using WinConditions = std::array<int, 8>;
//
//         enum WinningLine
//         {
//                 rowTop,
//                 rowMid,
//                 rowBot,
//                 colLeft,
//                 colMid,
//                 colRight,
//                 diagRight,
//                 diagLeft
//         };
//
// private:
//         Array2D m_board{};
//
// private:
//         void printBoard();
//         bool isFull();
//
// public:
//         Array2D board() { return m_board; }
//         bool validSquare(const Coordinate& coord);
//         bool update(Player* playerPtr, int square);
//         bool isWinner(Player* playerPtr);
// };
