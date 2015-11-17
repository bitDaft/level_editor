#ifndef FURS_H
#define FURS_H

#include <windows.h>
#include <iostream>
using namespace std;
class furs {
private:

  COORD cur, prev;
  char  adjCheck;
  static unsigned int m_furcount;
  unsigned short color;

public:

  furs();
  furs(COORD,
       unsigned short);
  virtual ~furs();

  COORD getcur()
  {
    return cur;
  }

  void Setcur(COORD a)
  {
    cur = a;
  }

  unsigned short getcolor()
  {
    return color;
  }

  unsigned int Getfurcount()
  {
    return m_furcount;
  }
};
#endif // FURS_H
