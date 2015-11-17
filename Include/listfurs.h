#ifndef LISTFURS_H
#define LISTFURS_H

#include <windows.h>
#include "furs.h"

class listfurs {
private:

  furs *f;
  listfurs *p;
  unsigned short m_gridval;
  static bool    puredelete;
  static unsigned int listCount;
  friend listfurs* getbefore(listfurs *);

public:

  listfurs(COORD,
	   unsigned short,
	   unsigned short);

  virtual ~listfurs();

  void             printfurs();
  friend listfurs* getfur(unsigned int);
  friend void      deleteall();

  unsigned short   Getgridval()
  {
    return m_gridval;
  }

  void Setgridval(unsigned short val)
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

  unsigned int getcount()
  {
    return listCount;
  }

  furs* getf()
  {
    return f;
  }
};
void      deleteall();
listfurs* getfur(unsigned int);

#endif // LISTFURS_H
