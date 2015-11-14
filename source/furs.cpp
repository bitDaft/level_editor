#include "furs.h"


unsigned int furs::m_furcount = 0;

furs::furs(COORD a, unsigned int x) : color(x)
{
  // ctor
  cur  = a;
  prev = cur;
  m_furcount++;
}

furs::~furs()
{
  // dtor
}
