#include "listfurs.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#define NO_OF_COLOR 6

using namespace std;

listfurs *_listfurs            = NULL;
bool      listfurs::puredelete = false;

listfurs* getfur(unsigned int a)
{
  listfurs *op = _listfurs;

  while (a != op->m_gridval) op = op->p;
  return op;
}

listfurs::listfurs(COORD a, unsigned int value)
{
  srand(time(0));
  f = new furs(a, rand() % NO_OF_COLOR);
  Setgridval(value);

  if (!_listfurs) p = NULL;
  else p = _listfurs;
  _listfurs = this;
}

void getbefore(listfurs *o)
{
  listfurs *op = _listfurs;

  while (o != (op->p)) op = op->p;
  op->p = o->p;
}

void listfurs::printfurs()
{
  listfurs *s = _listfurs;

  do
  { cout << "\n " << s->Getgridval() << " " << s;
    cout << " " << s->p;
    s = s->getp(); } while (s != NULL);
}

listfurs::~listfurs()
{
  if (puredelete)
  { delete f;
    m_gridval = -1;
    p         = NULL; }
  else
  { delete f;

    if (this != _listfurs)
    { getbefore(this); p = NULL; }
    else if (p)
    { _listfurs = _listfurs->p; p = NULL; }
    else _listfurs = NULL;
    m_gridval = -1; }
}

void deleteall()
{
  listfurs::puredelete = true;
  listfurs *in, *p = _listfurs;

  while (p != NULL)
  { in = p; p = in->p; delete in; }
  _listfurs            = NULL;
  listfurs::puredelete = false;
}
