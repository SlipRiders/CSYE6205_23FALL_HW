/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: intmatrix2.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has intmatrix2  class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#pragma once

/*----------------------------------------------------------------
NOTHING CAM BE ADDED except ../util/util.h
-----------------------------------------------------------------*/
#include "../util/util.h"


/*----------------------------------------------------------------
Declaration of intmatrix2 class
-----------------------------------------------------------------*/
class intmatrix2 {
public:
  //WRITE CODE.
  //CANNOT DECLARE ANY GLOBAL VARIABLE
    intmatrix2();

    intmatrix2(int rows, int cols);

    intmatrix2(int rows, int cols, int init_val);

    intmatrix2(const std::string& str);

    void print(const std::string& name) const;

    void fini();

    bool isEmpty() const;

    bool isEqual(const intmatrix2& other) const;

    intmatrix2 add(const intmatrix2& other) const;

    intmatrix2 mult(const intmatrix2& other) const;

    friend std::ostream& operator<<(std::ostream& os, const intmatrix2& mat);

    operator bool() const;

  //USE this as is. I will explain when I show
  static void makeShowOn() {_show = true;}
  static void makeShowOff() {_show = false;}
  static bool show() {return _show ;} 

private:
  static bool _show ; //MUST USE THIS
  //WRITE CODE BELOW
  //use xxx_ so that we know all variables are private
  std::vector<std::vector<int>> data_;
    int rows_;
    int cols_;
};




//EOF

