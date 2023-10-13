// #include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "board.cpp"
#include "player.h"
#include "printer.cpp"

using namespace std;

int main() {
    HANDLE hWindowConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD crd = { 120, 40 };
    SMALL_RECT src = { 0, 0, crd.X - 1, crd.Y - 1 };
    SetConsoleWindowInfo(hWindowConsole, true, &src);
    SetConsoleScreenBufferSize(hWindowConsole, crd);

    

    int n = 9;
    Board board = Board(n);

    Player *p1 = new Player(),
        *p2 = new Player();
    Printer printer = Printer();

    printer.printLegend(hWindowConsole);
    // while (true) {}

    board.playAt(0, 0, p1);
    board.playAt(4, 5, p2);
    board.playAt(6, 7, p1);

    printer.printBoard(board, p1);

    delete p1, p2;
    return 0;
}
