/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: test.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
DO NOT POST THIS FILE ON CANVAS
must include
raw.txt and unique.test as given in output  directory
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
g++ composition.cpp  test.cpp -o run.exe
cl composition.cpp  test.cpp -o run.exe
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
only includes here
-----------------------------------------------------------------*/
#include <crtdbg.h>
#include "composition.h"

/*----------------------------------------------------------------
test bench
-----------------------------------------------------------------*/
void test1() {
  ssn s1("657897","pan","India") ;
  cout << s1 << endl ;
  ssn s2("65-89-90","ssn","us") ;
  cout << s2 << endl ;

  ssn s3(s1) ;
  cout << s3 << endl ;
  s2 = s3 ;
  cout << s2 << endl ;
  cout << s3 << endl ;

  name n1("John") ;
  cout << n1 << endl ;
  name n2("John", "Smith") ;
  cout << n2 << endl ;
  name n3("John", "Smith", "Senior") ;
  cout << n3 << endl ;
  name n4("John", "Smith", "Senior", "Dr") ;
  cout << n4 << endl ;
}

/*----------------------------------------------------------------
test bench
-----------------------------------------------------------------*/
void test2() {
  list_of_graduates l(67) ;
  {
    ssn s("656-67-896","SSN","USA") ;
    name n("John", "Smith","Senior", "DR");
    dob d(8,14,1967) ;
    person p(s,n,d,"Singapore",false) ;
    graduate g(p,"Civil Engineering",2002) ;
    l.append(g) ;
  }

  {
    ssn s("JP9870","PAN","India") ;
    name n("Ram", "Rao","Subba") ;
    dob d(2,14,1977) ;
    person p(s,n,d,"USA") ;
    graduate g(p,"Doctor in Medicine",2020) ;
    l.append(g) ;
  }

  cout << l << endl ;
}

/*----------------------------------------------------------------
Main
-----------------------------------------------------------------*/
int main() { 
#ifdef _WIN32
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
  test1() ;
  test2() ;
  return 0 ;
}

//EOF

