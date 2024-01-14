/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
Filename: slist1.h
Edit：Xiaoyang chen By CLION
Time：2023/12/9 13:42
-----------------------------------------------------------------*/
#pragma once


/*----------------------------------------------------------------
Basic include files
-----------------------------------------------------------------*/
#include <iostream>
#include <fstream>

#include <iomanip>      // std::setprecision
using namespace std;

#ifdef _WIN32
#include <cassert>
#include <memory>

#else
#include <assert.h>
#endif

/*----------------------------------------------------------------
Must use T. if we want we change to double : #define T double
-----------------------------------------------------------------*/
#define T int

/*----------------------------------------------------------------
All forward declaration
-----------------------------------------------------------------*/
class node;
class slist1;

/*----------------------------------------------------------------
class Node
-----------------------------------------------------------------*/
class node {
public:
  //Write all public functions below
  node(T data) : data_(data), next_(nullptr) {}
  T& getData() { return data_; }
  const T& getData() const { return data_; }
  void setData(T data) { data_ = data; }
  node* getNext() const { return next_.get(); }
  void setNext(std::unique_ptr<node> next) { next_ = std::move(next); }
  std::unique_ptr<node>& getNextPtr() { return next_; }
  const std::unique_ptr<node>& getNextPtr() const { return next_; }

private:
  T  data_;
  std::unique_ptr<node> next_; //MUST USE. YOU CANNOT CHANGE THIS
  //YOU CANNOT ADD ANY DATA MEMBERS
  //You can have any number of private functions here
};

/*----------------------------------------------------------------
class slist
-----------------------------------------------------------------*/
class slist1 {
public:
  //Write all public functions below
  slist1();
  void prepend(T data);
  void append(T data);
  size_t size() const;
  const T* operator[](int index) const;
  friend std::ostream& operator<<(std::ostream& os, const slist1& list);
  bool find(T value) const;
  bool remove(T value) ;
  slist1(const slist1& other);
  slist1& operator=(const slist1& other);
  friend bool operator==(const slist1& lhs, const slist1& rhs);
  operator bool() const;
  friend bool operator!=(const slist1& lhs, const slist1& rhs);

private:
  std::unique_ptr<node> first_; //MUST USE. YOU CANNOT CHANGE THIS
  //YOU CAN ADD ANY OTHER DATA MEMBERS
  //For full grade both append and prepend MUST be O(1)
  
  //You can have any number of private functions here
  node* last_;
};


