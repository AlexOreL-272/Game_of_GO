#include "printer.h"

#include <windows.h>
#include <string>
#include <iostream>

using namespace std;

Printer::Printer(const char emptyCell, const char player1, const char player2)
    : emptyCellIcon(emptyCell), player1Icon(player1), player2Icon(player2) {

}

void Printer::printBoard(Board &board, const Player *player1) {

  const string LTTRS = "ABCDEFGHJKLMNOPQRSTUVWXYZ";
  int n = board.size;

  // Печать заголовков
  for (int i = 0; i < n / 10 + 2; i++) { // print offset created by row numbering
      cout << " ";
  }

  for (int i = 0; i < n; i++) {
      cout << LTTRS.at(i) << " ";
  }

  cout.put(cout.widen('\n'));
  cout.flush();

  for (int i = 0; i < n / 10 + 1; i++) {
      cout << " ";
  }
  cout << "+";

  for (int i = 0; i < n; i++) {
      cout << "--";
  }
  cout << "+";
  cout.put(cout.widen('\n'));
  cout.flush();

  // Печать каждого столбца
  for (int i = 0; i < n; i++) {
    // Печать столбцов слева
    for (int j = 0; j < n / 10 - i / 10; j++) { // print trailing spaces for formatting
       cout << " ";
    }
    cout << i << "|";

    for (int j = 0; j < n; j++) {
      Cell c = board.getCell(i, j);
      if (!c.isOccupied()) cout << this->emptyCellIcon;
      else if (c.getPlayerOwned() == player1) cout << this->player1Icon;
      else cout << this->player2Icon;

      cout << " ";
    }
    // Печать столбцов справа
    cout << "|" << i;
    cout.put(cout.widen('\n'));
    cout.flush();
  }

  // Печать ходов
  for (int i = 0; i < n / 10 + 1; i++) {
      cout << " ";
  }
  cout << "+";

  for (int i = 0; i < n; i++) {
      cout << "--";
  }
  cout << "+";
  cout.put(cout.widen('\n'));
  cout.flush();

  for (int i = 0; i < n / 10 + 2; i++) {
      cout << " ";
  }

  for (int i = 0; i < n; i++) {
      cout << LTTRS.at(i) << " ";
  }
  cout.put(cout.widen('\n'));
  cout.flush();
}

void Printer::printLegend(HANDLE con) {
    COORD cursorPos;
    DWORD written;

    cursorPos.X = 50;
    cursorPos.Y = 3;
    TCHAR arrs[] = L"Arrows to move the cursor";
    SetConsoleCursorPosition(con, cursorPos);
    WriteConsole(con, arrs, sizeof(arrs) / sizeof(TCHAR) - 1, &written, NULL);
    delete[] arrs;

    /*
    cursorPos.Y++;
    TCHAR quit[] = L"q: quit";
    SetConsoleCursorPosition(con, cursorPos);
    WriteConsole(con, quit, sizeof(quit) / sizeof(TCHAR) - 1, &written, NULL);
    delete[] quit;

    cursorPos.Y++;
    TCHAR n_game[] = L"n: start a new game";
    SetConsoleCursorPosition(con, cursorPos);
    WriteConsole(con, n_game, sizeof(n_game) / sizeof(TCHAR) - 1, &written, NULL);
    delete[] n_game;

    cursorPos.Y++;
    TCHAR confirm[] = L"enter: confirm your choise";
    SetConsoleCursorPosition(con, cursorPos);
    WriteConsole(con, confirm, sizeof(confirm) / sizeof(TCHAR) - 1, &written, NULL);
    delete[] confirm;

    cursorPos.Y++;
    TCHAR place[] = L"i: place a stone";
    SetConsoleCursorPosition(con, cursorPos);
    WriteConsole(con, place, sizeof(place) / sizeof(TCHAR) - 1, &written, NULL);
    delete[] place;
    */
}