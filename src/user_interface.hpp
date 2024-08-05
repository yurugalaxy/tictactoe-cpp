#pragma once

#include <string_view>
#include "tictactoe.hpp"

void clear();
void createMessage(std::string_view message);
void appendMessage(std::string_view message);
void printMessage();
void printLogo();
void printLine(int i, Game& game);
void printSeparator();
void printBoard(Game& game);
void draw();