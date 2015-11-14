#ifndef LISTFURS_H
#define LISTFURS_H

#include <windows.h>
#include "furs.h"

class listfurs {
private:

  furs *f;
  listfurs *p;
  unsigned int m_gridval;
  static bool  puredelete;
  friend  void getbefore(listfurs *);

public:

  listfurs(COORD,
	   unsigned int);
  virtual ~listfurs();

  void             printfurs();
  friend listfurs* getfur(unsigned int);
  friend void      deleteall();

  unsigned int     Getgridval()
  {
    return m_gridval;
  }

  void Setgridval(unsigned int val)
  {
    m_gridval = val;
  }

  listfurs* getp()
  {
    return p;
  }

  void setp(listfurs *o)
  {
    p = o;
  }
};
void      deleteall();
listfurs* getfur(unsigned int);
#endif // LISTFURS_H
