#include "furs.h"
#include <iostream>

using namespace std;

unsigned int furs::m_furcount = 0;

furs::furs(COORD a, unsigned short x)
{
  // ctor
  cur      = a;
  prev     = cur;
  adjCheck = 0;
  m_furcount++;
  color = x;
}

furs::~furs()
{
  // dtor
  cur      = prev = { 0, 0 };
  adjCheck = 0;
  m_furcount--;
}

furs::furs() : color(0)
{}
