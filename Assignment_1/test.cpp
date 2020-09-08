#include <iostream>
using namespace std;

int main(void)
{
  int m = 1, n = 2;
  int *pm = &m, *pn = &n, *r;
  r = pn;
  pn = pm;
  *pm = *pn +2;
  cout << m << "," << n << ","<< *r <<","<< *pm << endl;
}
