/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: examtest.cpp

On linux:
g++ exam.cpp examtest.cpp
valgrind a.out

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test exam object
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "exam.h"

/*----------------------------------------------------------------
YOUR TEST MUST WORK FOR ALL DATA

    378282246310005,
    371449635398431,
    378734493671000,
    5610591081018250,
    30569309025904,
    38520000023237,
    6011111111111117,
    6011000990139424,
    3530111333300000,
    5105105105105100,
    4111111111111111,
    4012888888881881,
    4222222222222,
    4012888888881880,
    1234567890123456,
-----------------------------------------------------------------*/
static void test() {
  //NOTE YOU CANNOT USE 
  // "378282246310005"  <------- THIS IS STRING 
  //MUST USE AS 378282246310005
}

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() { //mainexam
#ifdef _WIN32
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
  test();
  return 0;
}

//EOF

