/*----------------------------------------------------------------
Copyright (c) 2022 Author: Jagadeesh Vasudevamurthy
file: sarray.cpp
-----------------------------------------------------------------*/

#include "sarray.h"

bool Sarray::show = false;
unsigned long long Sarray::num_allocated = 0;
unsigned long long Sarray::num_freed = 0;

// 构造函数
Sarray::Sarray(unsigned n) : size_(n), ptr_(nullptr) {
    alloc_(size_);
}

// 拷贝构造函数
Sarray::Sarray(const Sarray& rhs) {
    if(rhs.show)
    {
        cout<<"calling copy constructor of size "<<rhs.size_<<endl;
    }
    copy_(rhs);
}
// 赋值运算符
Sarray& Sarray::operator=(const Sarray& rhs) {
    if(rhs.show)
    {
        cout<<"calling equal operator size "<<rhs.size_<<endl;
    }
    if (this != &rhs) {
        free_();
        copy_(rhs);
    }
    return *this;
}

#ifdef MOVE
// 移动构造函数
Sarray::Sarray(Sarray&& rhs) {
    if(rhs.show)
    {
        cout<<"calling move constructor of size "<<rhs.size_<<endl;
    }
    move_(rhs);
}

// 移动赋值运算符
Sarray& Sarray::operator=(Sarray&& rhs)  {
    if(rhs.show)
    {
        cout<<"calling move equal operator size "<<rhs.size_<<endl;
    }
    if (this != &rhs) {
        free_();
        move_(rhs);
    }
    return *this;
}
#endif

// 析构函数
Sarray::~Sarray() {
    free_();
}



// Swap 函数实现
void Swap(Sarray& a, Sarray& b)  {
        Sarray t=std::move(a);
        a=std::move(b);
        b=std::move(t);
}