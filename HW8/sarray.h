/*----------------------------------------------------------------
Copyright (c) 2022 Author: Jagadeesh Vasudevamurthy
file: sarray.h
-----------------------------------------------------------------*/
#pragma once

#include "../util/util.h"

#define T int

//MUST Attach two outputs with and without move
//#define MOVE


class Sarray {
public:
    explicit Sarray(unsigned size=0) ;
    Sarray(const Sarray& rhs);              // 拷贝构造函数
    Sarray& operator=(const Sarray& rhs);   // 赋值运算符

#ifdef MOVE
    //WRITE CODE
    Sarray(Sarray&& rhs) ;          // 移动构造函数
    Sarray& operator=(Sarray&& rhs) ; // 移动赋值运算符
#endif
    friend void Swap(Sarray& a, Sarray& b) ;
    ~Sarray(); // 析构函数
    static bool show;
    static unsigned long long num_allocated;
    static unsigned long long num_freed;
    static void pass_by_value(Sarray a)
    {
        cout<< "pass_by_value" <<endl;
    }

    static Sarray return_by_value(){
        Sarray t(2000);
        cout<< "return_by_value" <<endl;
        return t;
    }

private:
		unsigned size_;
		T* ptr_;

		//private funcions
        void alloc_(unsigned n){
            if(n){
                ptr_=new T[n];
            }
            if(show){
                cout<<"Allocating array of size "<<n<<endl;
            }
            num_allocated=num_allocated+size_;
        }

        void free_()
        {
            num_freed=num_freed+size_;
            if(show){
                if(ptr_){
                    cout<<"Freeng array of size "<<size_<<endl;
                }else{
                    cout<<"Nothing freed. Array was taken by move/equal operator"<<endl;
                }
            }
            delete[] ptr_;
        }

        void copy_(const Sarray& rhs)
        {
            size_=rhs.size_;
            alloc_(rhs.size_);
        }

        void move_(Sarray& rhs){
            size_=rhs.size_;
            ptr_=rhs.ptr_;
            rhs.ptr_= nullptr;
            rhs.size_=0;
        }



};



