/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: intmatrix2test.cpp

On linux:
g++ intmatrix2.cpp intmatrix2test.cpp
valgrind a.out

-23174-- REDIR: 0x3e7b87b800 (libc.so.6:free) redirected to 0x4a06acd (free)
==23174== 
==23174== HEAP SUMMARY:
==23174==     in use at exit: 0 bytes in 0 blocks
==23174==   total heap usage: 149 allocs, 149 frees, 75,520 bytes allocated
==23174== 
==23174== All heap blocks were freed -- no leaks are possible
==23174== 
==23174== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 4 from 4)
--23174-- 
--23174-- used_suppression:      4 U1004-ARM-_dl_relocate_object /tools/baton/valgrind/3.12.0/lib/valgrind/default.supp:1413
==23174== 
==23174== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 4 from 4)
[jag@xsjrdevl100 intmatrix2]$ 

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test intmatrix2 object
NOTHING CAN BE CHABGED IN THIS FILE
DO NOT UPLOAD THIS FILE TP CANVAS
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
NOTHING CAM BE ADDED except intmatrix2.h
-----------------------------------------------------------------*/
#include <crtdbg.h>
#include "intmatrix2.h"

/*----------------------------------------------------------------
test init and fini
-----------------------------------------------------------------*/
void test_init_fini() {
  intmatrix2 a;
  cout << "Matrix a" << endl;
  cout << a << endl;
  intmatrix2 b(3, 4);
  cout << "Matrix b" << endl;
  cout <<  b << endl;
  intmatrix2 c(2, 0, 7);
  cout << "Matrix c"  << endl;
  cout << c << endl;
  intmatrix2 d(0, 10, 7);
  cout << "Matrix d" << endl;
  cout <<  d << endl;
  intmatrix2 e(3, 10, 7);
  cout << "Matrix e"<< endl;
  cout << e << endl;
  intmatrix2 f("1 2|3 4|5 6");
  cout << "Matrix f" << endl;
  cout << f << endl;
  intmatrix2 g(" 1 2|3 4 |5 6 ");
  cout << "Matrix g"<< endl;
  cout <<  g << endl;
  assert(f.isEqual(g));
  assert(g.isEqual(f));
  {
    intmatrix2* m = new intmatrix2(g) ;
    cout << *m << endl ;
    delete m ;
  }
  {
    const int M = 5 ;
    intmatrix2** m = new intmatrix2*[M] ;
    for (int i = 0; i < M ; ++i) {
      m[i] = new intmatrix2(g) ;
    }
    for (int i = 0; i < M ; ++i) {
      cout << *m[i] ;
    }
    for (int i = 0; i < M ; ++i) {
      delete m[i] ;
    }
    delete [] m ;
  }

  intmatrix2 h(" 1 2 |3 4 |5 6 8 ");
  cout << "Matrix h" << endl;
  cout << h << endl;
  assert(!h);
  assert(!f.isEqual(h));
  h = a = f = e = d = c = b = g ;
  cout << "Matrix g" << endl;
  cout <<  g << endl;
  cout << "Matrix h" << endl;
  cout <<  h << endl;
  cout << "Matrix e" << endl;
  cout <<  e << endl;
}

/*----------------------------------------------------------------
test add1
-----------------------------------------------------------------*/
void test_add1(const char* as, const char* bs, const char* anss) {
  intmatrix2 a(as);
  cout << "Matrix a" << endl;
  cout <<  a << endl;
  intmatrix2 b(bs);
  cout << "Matrix b" << endl;
  cout <<  b << endl;
  intmatrix2 s = a.add(b);
  cout << "Matrix s" << endl;
  cout <<  s << endl;
  intmatrix2 ans(anss);
  cout << "Matrix expected ans" << endl;
  cout <<  ans << endl;
  assert(s.isEqual(ans));
  assert(ans.isEqual(s));
}

/*----------------------------------------------------------------
test add
-----------------------------------------------------------------*/
void test_add() {
  test_add1("7 9 11|13 15 17 ", " 6 8 10| 12 14 16 ", "13 17 21 | 25 29 33");
  test_add1("1 2 3|4 5  6 ", "1 2  ", "");
}

/*----------------------------------------------------------------
test mult1
-----------------------------------------------------------------*/
void test_mult1(const char* as, const char* bs, const char* anss) {
  intmatrix2 a(as);
  cout << "Matrix a" << endl;
  cout <<  a << endl;
  intmatrix2 b(bs);
  cout << "Matrix b" << endl;
  cout <<  b << endl;
  intmatrix2 s = a.mult(b);
  cout << "Matrix s" << endl;
  cout <<  s << endl;
  intmatrix2 ans(anss);
  cout << "matrix expected ans" << endl;
  cout <<  ans << endl;
  assert(s.isEqual(ans));
  assert(ans.isEqual(s));
  cout << "----------------------------------\n";
}

/*----------------------------------------------------------------
test mult
-----------------------------------------------------------------*/
void test_mult() {
  test_mult1("1 2 3", " 2 1 3 | 3 3 2| 4 1 2  ", "20 10 13");
  test_mult1("3 4 2", "13 9 7 15|8 7 4 6| 6 4 0 3 ", "83 63 37 75");
  test_mult1("3", "5 2 11|9 4 14", "15 6 33|27 12 42");
  test_mult1("5 2 11|9 4 14", "3 ", "15 6 33|27 12 42");
  const char* a = "3 9 0 2 2 9 5 2|0 2 2 1 9 6 6 8|7 5 6 1 4 9 8 9|3 3 2 9 2 1 7 4|1 9 0 1 2 9 5 2|4 2 0 3 7 3 9 1|5 9 0 6 6 7 8 2|9 3 4 6 8 4 9 1";
  const char* b = "6 1 6 0 8 3 0 0|6 8 9 0 6 6 7 2|4 8 2 0 5 4 6 7|2 4 4 2 2 6 9 8|4 8 2 2 4 6 4 1|1 5 5 6 4 7 5 5|7 4 6 5 0 6 5 3|2 3 7 0 1 3 8 5";
  const char* s = "132 170 200  87 128 186 175 106|122 186 166  86  92 182 195 123|197 235 267 104 179 243 253 178|128 140 164  63  86 162 194 140|118 164 184  85 110 174 166  98|138 142 144  83  91 162 137  82|187 222 244 106 160 244 232 141|201 212 210  97 171 230 204 142";
  test_mult1(a, b, s);
  test_mult1("7 3|2 5 | 6 8| 9 0", "8 14 0 3 1|7 11 5 91 3|8 4 19 5 57", "");
}

/*----------------------------------------------------------------
test bed
-----------------------------------------------------------------*/
static void testbed() {
  intmatrix2::makeShowOn() ;
  test_init_fini();
  test_add();
  test_mult();
}

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() { //mainintmatrix2
#ifdef _WIN32
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
  testbed();
  cout << "All test passed. Your output shoyld NOT show  any memory leaks\n" ;
  cout << "Write my midterm review write now\n";
  return 0;
}

//EOF


