#include "listfurs.h"
#include "colors.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>

using namespace std;

#define MX    20
#define MY    10

void gotoxy(COORD d)
{
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), d);
}

void printgrid()
{
  uint8_t register i, j;

  for (i = 0; i < 10; i++)
  {
    for (j = 0; j < 20; j++)
    {
      if ((j == 0) || (i == 0)) cout << "+-";
      else cout << " -";
    }
    cout << "+\n|";

    for (j = 0; j < 20; j++)
    {
      cout << " |";
    }
    cout << "\n";
  }

  for (i = 0; i < 20; i++)
  {
    cout << "+-";
  }
  cout << "+";
}

int hitkey()
{
  int x = 0;

  if (kbhit())
  {
    x = getch();

    if (!x || (x == 224)) x = getch();
  }
  return x;
}

void clearlist(COORD pos, listfurs  *top)
{
  listfurs *temp = top; gotoxy(pos);

  while (temp)
  {
    temp = temp->getp();
    cout << "                          ";
    pos.Y += 1;
    gotoxy(pos);
  }
  cout << "                            ";
}

void producelist(COORD pos, listfurs  *top)
{
  listfurs *temp = top; pos.Y += 1;

  clearlist(pos, top);
  gotoxy({ pos.X, short(pos.Y - 2) });
  cout.width(8); cout << "Gridval ";
  cout.width(10); cout << "fur point ";
  cout.width(10); cout << "fur->next";
  gotoxy({ pos.X, short(pos.Y - 1) });
  cout << "============================";

  while (temp)
  {
    gotoxy(pos);
    cout.width(7);
    cout << temp->Getgridval() << " ";
    cout.width(9);
    cout << temp;
    cout.width(10);
    cout << temp->getp();
    temp   = temp->getp();
    pos.Y += 1;
  }
}

// TODO complete menu in pointer list pos (45,0)
void menu()
{
  gotoxy({ 45, 0 });
  cout << "hi";
}

// TODO implement features like save edit delete export and view
int main()
{
  bool grid[MY][MX] {};
  listfurs *ptr = NULL;
  unsigned int ch, value = 0;
  COORD        d = { 1, 1 };

  printgrid();
  gotoxy(d);
  menu();
  cin.ignore();
  producelist({ 45, 1 }, ptr);

  while (1)
  {
    if ((ch = hitkey()))
    {
      switch (ch) {
      case 72: {
	if (d.Y > 1)
	{ d.Y -= 2; value -= MX; }
	break;
      }

      case 80: {
	if (d.Y < 19)
	{ d.Y += 2; value += MX; }
	break;
      }

      case 75: {
	if (d.X > 1)
	{  d.X -= 2; value -= 1; }
	break;
      }

      case 77: {
	if (d.X < 39)
	{ d.X += 2; value += 1; }
	break;
      }

      case 13: {
	bool& t = grid[value / MX][value % MX];

	if (!t) ptr = new listfurs(d, value);
	else
	{
	  if (ptr == getfur(value))
	  { if (!ptr->getp()) ptr = NULL;
	    else ptr = ptr->getp(); }
	  delete getfur(value);
	}
	producelist({ 45, 1 }, ptr);
	gotoxy(d);
	t ^= 1;

	if (t) cout << char(177);
	else cout << " ";
	break;
      }

      case 's': {
	// #TODO:0 do save function
	// TODO complete furs files
	break;
      }

      case 98: {
	// HACK quick exit
	// IDEA make it replace fur linker list with menu,the grid should
	// sustain and draw furs according to option

	goto hi;
      }
      }
      gotoxy(d);
    }
  }
hi:
  deleteall();
  return 0;
}
