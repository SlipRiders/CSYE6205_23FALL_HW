/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: String2DataTest.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
cd C:\Users\jag\OneDrive\vasu\work\c++\course\objects\String2Data
cl String2Data.cpp String2Data.cpp String2DataTest.cpp -o run.exe
-----------------------------------------------------------------*/


/*----------------------------------------------------------------
             YOU CANNOT CHANGE ANYTHING IN THIS FILE
             DO NOT UPLOAD THIS FILE ON CANVAS
-----------------------------------------------------------------*/
#include <crtdbg.h>
#include "String2Data.h"


/*----------------------------------------------------------------
This code is left for testing conversion
Enter a value: false
Value is a bool: 0
Enter a value: true
Value is a bool: 1
Enter a value: -0
Value is an long: 0
Enter a value: 567890
Value is an long: 567890
Enter a value: -56.89
Value is a double: -56.89
Enter a value: 23r
Value is a string: 23r
Enter a value:
-----------------------------------------------------------------*/
void String2Data::test_conversion() {
  cout << "Will loop until you type: quit or exit\n";
  cout << "Must infer data type: bool, long, double, string from input\n";
  while (1) {
    std::string input;
    std::cout << "Enter a value: ";
    std::cin >> input;
    String2Data s(input);
    {
      bool isbool = false;
      int d = s.string_2_bool(isbool);
      if (isbool) {
        std::cout << "Value is a bool: " << std::boolalpha << d << std::endl;
        continue;
      }
    }

    {
      bool islong = false;
      long d = s.string_2_long(islong);
      if (islong) {
        std::cout << "Value is an long: " << d << std::endl;
        continue;
      }
    }

    {
      bool isdouble = false;
      double d = s.string_2_double(isdouble);
      if (isdouble) {
        std::cout << "Value is a double: " << d << std::endl;
        continue;
      }
    }
    std::cout << "Value is a string: " << input << std::endl;
    if (s.str_ == "quit" || s.str_ == "exit") {
      return;
    }
  }
}



/*----------------------------------------------------------------
main
---------------------------------------------------------------- - */
int main() {
#ifdef _WIN32
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
  String2Data::test_conversion();
  return 0;
}