/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: composition.h
-----------------------------------------------------------------*/


/*----------------------------------------------------------------
RUN TWICE. OUTPUT MUST BE SAME
-----------------------------------------------------------------*/
//#define RAWPOINTER
#define UNIQUEPOINTER


#pragma once
/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include <iostream>
#include <fstream>

#include <iomanip>      // std::setprecisio
using namespace std;

#ifdef _WIN32
#include <cassert>
#include <ctime>
#include <memory>

#else
#include <assert.h>
#include <time.h>
#endif

/*----------------------------------------------------------------
Basic defines here 
-----------------------------------------------------------------*/
static const int SHOW = 1;

/*----------------------------------------------------------------
mstring class
-----------------------------------------------------------------*/
class mstring{
public:
    // Constructor
    mstring(const char* str);

    // Destructor
    ~mstring();

    // Copy constructor
    mstring(const mstring& other);

    // Move constructor
    mstring(mstring&& other) noexcept;

    // Copy assignment operator
    mstring& operator=(const mstring& other);

    // Move assignment operator
    mstring& operator=(mstring&& other) noexcept;

    mstring(const std::string& str) : s_(new std::string(str)) {}

    const string& str() const {
#ifdef RAWPOINTER
        return *s_; // for raw pointers
#endif
#ifdef UNIQUEPOINTER
        return *s_.get(); // for unique_ptr
#endif
    }


private:
  //data
#ifdef RAWPOINTER
  string* s_;
#endif
#ifdef UNIQUEPOINTER   
  unique_ptr<string> s_;
#endif
 
};
class graduate;

/*----------------------------------------------------------------
SSN class
-----------------------------------------------------------------*/
class ssn{
public:
    ssn(const char* s, const char* n, const char* c);
    ssn(const ssn& other);
    ssn& operator=(const ssn& other)  ;
    friend ostream& operator<<(ostream& os, const ssn& obj);
    friend ostream& operator<<(ostream& os, const graduate& g);
    ~ssn(); // Destructor
private:
  //data
  mstring ssn_ ; //2156789PQ
  mstring name_ ; //SSN/Pan etc
  mstring country_ ; //Country issued
};

/*----------------------------------------------------------------
name class
-----------------------------------------------------------------*/
class name{
public:
    name(const char* f, const char* l = "", const char* m = "", const char* t = "");
    name(const name& other);
    name& operator=(const name& other) ;
    friend ostream& operator<<(ostream& os, const name& obj);
    friend ostream& operator<<(ostream& os, const graduate& g);
    ~name();
private:
  mstring fname_;
  mstring lname_ ;
  mstring mname_ ;
  mstring title_ ;
};

/*----------------------------------------------------------------
date of birth class
-----------------------------------------------------------------*/
class dob{
public:
    dob(unsigned int month, unsigned int day, unsigned int year);
    ~dob();
    friend ostream& operator<<(ostream& os, const graduate& g);
private:
  //data
  unsigned int month_ ;
  unsigned int day_ ;
  unsigned int year_ ;
};



/*----------------------------------------------------------------
person class
-----------------------------------------------------------------*/
class person{
public:
    person(const ssn& ssn_obj, const name& name_obj, const dob& dob_obj,const mstring& place, bool is_alive);
    person(const ssn& ssn_obj, const name& name_obj, const dob& dob_obj,const mstring& place);
    ~person();
    friend ostream& operator<<(ostream& os, const graduate& g);
private:
  //data
  ssn ssn_ ;
  name name_ ;
  dob _dob ;
  mstring _currentp_lace_of_residence ;
  bool _isalive ;
};

/*----------------------------------------------------------------
graduate class
-----------------------------------------------------------------*/
class graduate{
public:
  graduate(const person& p, const mstring& m, int y):p_(p),degree_awarded_(m),year_(y){
    if (SHOW) {
      cout << "in graduate constructor " << endl ;
    }
  }
  ~graduate() {
    if (SHOW) {
      cout << "in graduate disstructor " << endl ;
    }
  }

  friend ostream& operator<<(ostream& os, const graduate& g);

private:
  person p_ ;
  mstring degree_awarded_ ;
  int year_ ;
};

/*----------------------------------------------------------------
graduate class
-----------------------------------------------------------------*/
class list_of_graduates{
public:
  list_of_graduates(int maxsize = 50):maxsize_(maxsize),size_(0),list_(nullptr) {
    if (SHOW) {
      cout << "in list_of_graduates constructor " << endl ;
    }
    //WRITE CODE
      // 分配一个足够大的指针数组来存储 graduate 对象的指针
      list_ = new graduate*[maxsize_];
      for (int i = 0; i < maxsize_; ++i) {
          list_[i] = nullptr;  // 初始化数组中的每个元素为 nullptr
      }
  }
  ~list_of_graduates() {
    if (SHOW) {
      cout << "in list_of_graduates disstructor " << endl ;
    }
    //WRITE CODE
      for (int i = 0; i < size_; ++i) {
          delete list_[i];  // 释放每个 graduate 对象
      }
      delete[] list_;  // 释放存储指针的数组
  }
 
  void append(const graduate& g) {
    //WRITE CODE
      if (size_ < maxsize_) {
          list_[size_] = new graduate(g);
          ++size_;
      }
  }
  //WRITE cout
  friend ostream& operator<<(ostream& os, const list_of_graduates& lg);

private:
  int maxsize_ ;
  int size_ ;
  graduate** list_ ;
};

//EOF

