#ifndef FURS_H
#define FURS_H

#include <windows.h>

class furs {
private:

  COORD cur, prev;
  char  adjCheck;
  static unsigned int  m_furcount;
  const unsigned short color;

public:

  furs(COORD,
       unsigned int);
  virtual ~furs();

  unsigned int Getfurcount()
  {
    return m_furcount;
  }
};
#endif // FURS_H
