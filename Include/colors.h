#ifndef COLORS_H
#define COLORS_H

#include <windows.h>

// List of colors
// #TODO:1 complete color handling

#define blue  SetConsoleTextAttribute(GetStdHandle( \
					STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
#define black SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), \
				      nullptr);
#define red SetConsoleTextAttribute(GetStdHandle( \
				      STD_OUTPUT_HANDLE), FOREGROUND_RED);
#define green SetConsoleTextAttribute(GetStdHandle( \
					STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
#define lblue SetConsoleTextAttribute(GetStdHandle(	    \
					STD_OUTPUT_HANDLE), \
				      FOREGROUND_BLUE | FOREGROUND_INTENSITY);
#define lred SetConsoleTextAttribute(GetStdHandle(	   \
				       STD_OUTPUT_HANDLE), \
				     FOREGROUND_RED | FOREGROUND_INTENSITY);
#define lgreen SetConsoleTextAttribute(GetStdHandle(	     \
					 STD_OUTPUT_HANDLE), \
				       FOREGROUND_GREEN |    \
				       FOREGROUND_INTENSITY);
#define pink SetConsoleTextAttribute(GetStdHandle(			\
				       STD_OUTPUT_HANDLE),		\
				     FOREGROUND_BLUE | FOREGROUND_RED |	\
				     FOREGROUND_INTENSITY);
#define purple SetConsoleTextAttribute(GetStdHandle(	     \
					 STD_OUTPUT_HANDLE), \
				       FOREGROUND_BLUE | FOREGROUND_RED);
#define cyan SetConsoleTextAttribute(GetStdHandle(			  \
				       STD_OUTPUT_HANDLE),		  \
				     FOREGROUND_BLUE | FOREGROUND_GREEN | \
				     FOREGROUND_INTENSITY);
#define turqoise SetConsoleTextAttribute(GetStdHandle(	       \
					   STD_OUTPUT_HANDLE), \
					 FOREGROUND_BLUE | FOREGROUND_GREEN);
#define yellow SetConsoleTextAttribute(GetStdHandle(			   \
					 STD_OUTPUT_HANDLE),		   \
				       FOREGROUND_RED | FOREGROUND_GREEN | \
				       FOREGROUND_INTENSITY);
#define mustard SetConsoleTextAttribute(GetStdHandle(	      \
					  STD_OUTPUT_HANDLE), \
					FOREGROUND_RED | FOREGROUND_GREEN);
#define white SetConsoleTextAttribute(GetStdHandle(					    \
					STD_OUTPUT_HANDLE),				    \
				      FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | \
				      FOREGROUND_INTENSITY);
#define lgray SetConsoleTextAttribute(GetStdHandle(			  \
					STD_OUTPUT_HANDLE),		  \
				      FOREGROUND_RED | FOREGROUND_GREEN | \
				      FOREGROUND_BLUE);
#define grey  SetConsoleTextAttribute(GetStdHandle(	    \
					STD_OUTPUT_HANDLE), \
				      FOREGROUND_INTENSITY);


void changecolor(unsigned short a)
{
	switch(a)
	{
		case 1:blue;break;
		case 2:red;break;
		case 3:lgreen;break;
		case 4:pink;break;
		case 5:yellow;break;
		case 6:lblue;break;
	}
}


#endif // ifndef COLORS_H
// keywords in comments
// CHANGED
// REVIEW
// FIXME
// TODO
// HACK
// IDEA
// NOTE
// XXX
