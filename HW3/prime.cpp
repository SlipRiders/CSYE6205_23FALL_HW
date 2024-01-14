/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: prime.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has prime class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "prime.h"
#include "cmath"
/*----------------------------------------------------------------
Definition of routines of prime class
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
Space allocation of static must be in CPP file
-----------------------------------------------------------------*/
unsigned long long  prime::kount = 0ll;

/*----------------------------------------------------------------
WRITE CODE BELOW
-----------------------------------------------------------------*/
void prime::upto_n_minus_1_(){
    for (int i = 2; i <= n_; ++i) {
        bool isPrime = true;
        for (int j = 2; j < i; ++j) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
            incr_kount(); // 记录工作量
        }
        if (isPrime) {
            v_.push_back(i);
        }
    }
}

void prime::upto_n_by_2_() {
    for (int i = 2; i <= n_; ++i) {
        bool isPrime = true;
        for (int j = 2; j <= i / 2; ++j) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
            incr_kount(); // 记录工作量
        }
        if (isPrime) {
            v_.push_back(i);
        }
    }
}

void prime::sqrt_of_n_() {
    for (int i = 2; i <= n_; ++i) {
        bool isPrime = true;
        for (int j = 2; j <= std::sqrt(i); ++j) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
            incr_kount(); // 记录工作量
        }
        if (isPrime) {
            v_.push_back(i);
        }
    }
}

void prime::upto_prime_() {
    if (n_ >= 2) {
        v_.push_back(2);
    }
    for (int i = 3; i <= n_; i += 2) { // 只检查奇数，因为偶数肯定不是质数
        bool isPrime = true;
        for (int prime : v_) {
            incr_kount(); // 记录工作量
            if (prime * prime > i) { // 如果质数的平方大于i，则停止检查
                break;
            }
            if (i % prime == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            v_.push_back(i);
        }
    }
}

void prime::sieve_of_eratosthenes_() {
    vector<bool> isPrime(n_ + 1, true);
    isPrime[0] = isPrime[1] = false; // 0和1不是质数
    for (int i = 2; i <= std::sqrt(n_); ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n_; j += i) {
                incr_kount(); // 记录工作量
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n_; ++i) {
        if (isPrime[i]) {
            v_.push_back(i);
        }
    }
}

prime::prime(vector<int>& v, const string& name, int n) : v_(v), algname_(name), n_(n) {
    if (name == "upto_n_minus_1") {
        upto_n_minus_1_();
    } else if (name == "upto_n_by_2") {
        upto_n_by_2_();
    } else if (name == "sqrt_of_n") {
        sqrt_of_n_();
    } else if (name == "upto_prime"){
        upto_prime_();
    } else if (name == "sieve_of_eratosthenes"){
        sieve_of_eratosthenes_();
    }
}

//EOF

