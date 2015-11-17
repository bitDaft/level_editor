#include "listfurs.h"
#include "colors.h"
#include "furs.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>


using namespace std;
//unsigned short GRIDSIZE = 10;

// To get grid in ratio of almost square looking it is advised to keep MX=2*MY
// only change MY ,unless you need specific size grid
#define MX    (MY * 2)
#define MY    10//GRIDSIZE


void gotoxy(COORD d)
{
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), d);
}

void initscreen()
{
  unsigned short register i, j;

  lblue;
  gotoxy({ 0, 0 });

  for (i = 0; i < 80; i++)
    for (j = 0; j < 25; j++) cout << char(177);
  white;
  gotoxy({ 0, 0 });
}

void printgrid() {
  uint8_t register i, j;

  for (i = 0; i < MY; i++) {
    for (j = 0; j < MX; j++)
      if ((j == 0) || (i == 0)) cout << "+-";
      else cout << " -";
    cout << "+\n|";

    for (j = 0; j < MX; j++) cout << " |";
    cout << "\n";
  }

  for (i = 0; i < MX; i++) cout << "+-";
  cout << "+";
}

int hitkey() {
  int x = 0;

  if (kbhit()) {
    x = getch();

    if (!x || (x == 224)) x = getch();
  }
  return x;
}

void clearlist(COORD pos, int line)
{
  gotoxy(pos);

  while (line)
  {
    cout << "                            ";
    pos.Y += 1;
    gotoxy(pos);
    line--;
  }
  cout << "                            ";
}

void producelist(COORD pos, listfurs  *top)
{
   pos.Y += 1;

  clearlist(pos, 20);
  gotoxy({ pos.X, static_cast<short>(pos.Y - 2) });
  cout.width(8); cout << "Gridval ";
  cout.width(10); cout << "fur point ";
  cout.width(10); cout << "fur->next";
  gotoxy({ pos.X, short(pos.Y - 1) });
  cout << "============================";
  gotoxy({ 1, 1 });

  while (top)
  {
    gotoxy(pos);
    cout.width(7);
    cout << top->Getgridval() << " ";
    cout.width(9);
    cout << top;
    cout.width(10);
    cout << top->getp();
    top   = top->getp();
    pos.Y += 1;
  }
}

int menu()
{
  unsigned int dir = 0;
  short y { 0 };

  gotoxy({ 45, y++ }); cout << "+=======================+";
  gotoxy({ 45, y++ }); cout << "|          MENU         |";
  gotoxy({ 45, y++ }); cout << "+=======================+";
  gotoxy({ 45, y++ }); cout << "|      NEW LAYOUT       |";
  gotoxy({ 45, y++ }); cout << "|      OPEN LAYOUT      |";
  gotoxy({ 45, y++ }); cout << "|      DELETE LAYOUT    |";
 // gotoxy({ 45, y++ }); cout << "|      GRID SIZE(deprec)|";//deprecated option
  gotoxy({ 45, y++ }); cout << "|      EXIT             |";
  gotoxy({ 45, y++ }); cout << "+-----------------------+";
  y = 3;
  gotoxy({ 50, y });
  cout << ">";
  gotoxy({ 79, 24 });

  while ((dir = hitkey()) != 13) {
    switch (dir)
    {
    case 72:

      if (y > 3) {
	gotoxy({ 50, y }); cout << " "; y--;
      }
      gotoxy({ 50, y });
      cout << ">"; gotoxy({ 79, 24 }); break;

    case 80:

      if (y < 6) {
	gotoxy({ 50, y }); cout << " "; y++;
      }
      gotoxy({ 50, y });
      cout << ">"; gotoxy({ 79, 24 }); break;
    }
  }
  y -= 3;
  return y;
}
void drawbool(bool gr[MY][MX])
{
  unsigned register int i,j;
  listfurs *p;
   furs *op;
   unsigned short ch;
  for ( i = 0; i < MY; ++i)
  {
    /* code */
    for ( j = 0; j < MX; ++j)
    {
      // cout<<"hi";
       gotoxy({static_cast<short>(j*2+1),static_cast<short>(i*2+1)});

      if(gr[i][j]==true)
      {// cout<<"hi";
        p=&getfur(i*20+j);
        // cout<<"hi";
      op=p->getf();
      // cout<<"hi";
      ch=op->getcolor();
        changecolor(ch);
        gotoxy({static_cast<short>(j*2+1),static_cast<short>(i*2+1)});

        cout<<(char)177;
        white;
      }
      else cout<<" ";
    }
  }
}

// TODO implement features like save edit delete export and view
int main()
{
  bool saved     = false;
  bool bckToMenu = false, quit = false;
  listfurs *ptr  = NULL;
  unsigned int ch, value = 0;
  COORD        d = { 1, 1 };
  bool gchanged=false;

  do {
    saved=false;
     initscreen();

    Sleep(250);
    printgrid();
    bckToMenu = false;
    int opt;
bool grid[MY][MX];
unsigned short cnt;
unsigned short tcnt;
//unsigned short val=0;
ifstream infur;

switch(opt = menu()){
    case 1:
    {
      infur.open("grid.dat", ios::binary | ios::in);infur.seekg(0);
//furs *pt=NULL;

      if (infur.is_open()) { // TODO figure out this shit
        infur.read(reinterpret_cast<char *>(grid),sizeof(grid));//grid
        drawbool(grid);
        infur.read(reinterpret_cast<char *>(&cnt),sizeof(unsigned short));
        //count done
        tcnt=cnt;
        furs *pt=new furs();
        while(tcnt--)
        {
        infur.read(reinterpret_cast<char *>(&pt),sizeof(furs));
        infur.read(reinterpret_cast<char *>(&cnt),sizeof(cnt));
        ptr=new listfurs(pt->getcur(),cnt,pt->getcolor());
      }
        infur.close();
      }
      else {clearlist({45,0},20);
        gotoxy({ 45, 3 });
  cout << "Unable to open file" << endl;
  gotoxy({ 45, 4 });
	cout << "Press <Enter>" << endl;

  cin.ignore();
      }
      quit = false;
      bckToMenu = false;
      break;
    }

    case 2:{
    ifstream  fin("grid.dat",ios::in);
    if(fin.is_open()){
      fin.close();
        remove("grid.dat");
      }
       bckToMenu = true; quit = false;} break;

    case 3:
      quit = true; bckToMenu = true;
  }

  gchanged=false;
    if (opt==0||!infur.is_open()){
          for (register int i = 0; i < MY; i++)
      for (register int j = 0; j < MX; j++)
        grid[i][j] = 0;}

    if (!quit) {
      if(!bckToMenu){

    drawbool(grid);
      producelist({ 45, 1 }, ptr);}
    }
  else break;
  d = { 1, 1 };
      gotoxy(d);
      value=0;

    while (!bckToMenu)
    {
      if ((ch = hitkey()))
      {
  switch (ch) {
  // movement
  case 72: {
    if (d.Y > 1)
    { d.Y -= 2; value -= MX; }
    break;
  }

  case 80: {
    if (d.Y < (2 * MY - 1))
    { d.Y += 2; value += MX; }
    break;
  }

  case 75: {
    if (d.X > 1)
    {  d.X -= 2; value -= 1; }
    break;
  }

  case 77: {
    if (d.X < (2 * MX - 1))
    { d.X += 2; value += 1; }
    break;
  }


  case 13: { saved = false;gchanged=true;
       bool& t = grid[value / MX][value % MX];

       if (!t) ptr = new listfurs(d, value,0);
       else
       {
         if (ptr == &getfur(value)) {
           ptr = ptr->getp();
         }
         delete &getfur(value);
       }
       producelist({ 45, 1 }, ptr);
       gotoxy(d);
       t ^= 1;

      drawbool(grid);

       break; }

  case 98: {
    bckToMenu = true;
    char x;
    if (saved)
    { deleteall();ptr=NULL; break; }
    else
    {
      clearlist({ 45, 0 }, 20);
      gotoxy({ 45, 3 });cout << "Save changes?(y/n)";
      gotoxy({ 45, 4 });cout << "Press <Enter> to confirm";
      gotoxy({ 45, 5 });cout << ">>";

      cin >> x;
      if (x!='n' && x!='y') {x='n';}
      if(x == 'n'||x=='N') { deleteall(); ptr=NULL ;break; }
    }
  }

  case 's': {if(gchanged&&ptr){
        ofstream outfur("grid.dat", ios::binary | ios::out | ios::trunc);

        if (outfur.is_open()) {
          listfurs *t=NULL,*temp = ptr;
          furs     *pt   = temp->getf();
          outfur.write(reinterpret_cast<char *>(grid), sizeof(grid));//grid
          unsigned short sp=temp->getcount();
          outfur.write(reinterpret_cast<char *>(&sp),sizeof(sp));//count of list
    while(t!=ptr){
      temp=ptr;
          while (temp->getp()!=t)
          {
            temp = temp->getp();
          }
          pt = temp->getf();
          outfur.write(reinterpret_cast<char *>(pt), sizeof(furs));//fur
          sp=temp->Getgridval();
          outfur.write(reinterpret_cast<char *>(&sp),sizeof(sp));//gridval
          t=temp;
        }
          outfur.close();
        }
        saved = true;
        if (bckToMenu) deleteall();
       gchanged=false;} break;
   }
  }
  gotoxy(d);
      }

    }
  } while (!quit);
  return 0;
}
