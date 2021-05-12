#include "menu.h"

using namespace std;

char gotoXY(int x, int y) //functie adaptata dupa cea gasita la: http://www.cplusplus.com/forum/general/56892/
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD CursorPosition;
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console,CursorPosition);
}
