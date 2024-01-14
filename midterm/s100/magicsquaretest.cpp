/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: magicsquaretest.cpp

On linux:
g++ magicsquare.cpp magicsquaretest.cpp
valgrind a.out

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test magicsquare object. DO NOT POST THIS FILE IN CANVAS
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include <crtdbg.h>
#include "magicsquare.h"

/*----------------------------------------------------------------
verify
for n = 3

6 1 8
7 5 3
2 9 4

YOU CANNOT CHANGE THIS ROUTINE
-----------------------------------------------------------------*/
int verify(magicsquare& a, int n, int tsum) {
  //Make sure all rows have sum = tsum
  for (int r = 0; r < n; ++r) {
    int sum = 0;
    for (int c = 0; c < n; ++c) {
      sum = sum + a.getRC(r, c);
    }
    if (tsum != sum) {
      return sum;
    }
  }
  //Make sure all coulmns have sum = tsum
  for (int c = 0; c < n; ++c) {
    int sum = 0;
    for (int r = 0; r < n; ++r) {
      sum = sum + a.getRC(r, c);
    }
    if (tsum != sum) {
      return sum;
    }
  }
  //Make sure diagonal \ have sum = tsum
  int sum = 0;
  for (int r = 0, c = 0; r < n; ++r, ++c) {
    sum = sum + a.getRC(r, c);
  }
  if (tsum != sum) {
    return sum;
  }
  //Make sure diagonal / have sum = tsum
   sum = 0;
  for (int r = 0, c = n - 1; r < n; ++r, --c) {
    sum = sum + a.getRC(r, c);
  }
  if (tsum != sum) {
    return sum;
  }
  return tsum;
}

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() { 
#ifdef _WIN32
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
  magicsquare::show = true;
  for (int i = 3; i < 100; i+=2) {
    magicsquare b(i);
    magicsquare a(b);
    magicsquare c = a;
    a = b = c = c; //if this passes means ONLY u know C++
    cout << a << endl;
    int n2 = i * i;
    int sum1ton2 = (n2 * (n2 + 1)) / 2;
    int tsum = sum1ton2 / i;
    int v = verify(a, i, tsum);
    if (v != tsum) {
      cout << "Your sum = " << v << " Expected sum is = " << tsum << endl;
      assert(0);
    }
  }
  cout << "There should be no memory leak for 100 marks\n";
  return 0;
}

//EOF

