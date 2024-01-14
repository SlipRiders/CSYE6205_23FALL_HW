/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: magicsquare.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has magicsquare class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "magicsquare.h"

/*----------------------------------------------------------------
space for static
-----------------------------------------------------------------*/
bool magicsquare::show = false;

magicsquare::magicsquare(int n) : n_(n) {
    std::cout << "In constructor " << n_ << std::endl;
    matrix_ = new std::vector<std::vector<int>*>();

    for(int i = 0; i < n_; ++i) {
        matrix_->push_back(new std::vector<int>(n_, 0));
    }

    int num = 1;
    int row = 0;
    int col = n_ / 2;

    while(num <= n_ * n_) {
        if(row < 0 && col < 0) {
            row += 2;
            col++;
        } else {
            if(row < 0) {
                row = n_ - 1;
            }

            if(col < 0) {
                col = n_ - 1;
            }
        }
        if((*matrix_)[row]->at(col) == 0) {
            (*matrix_)[row]->at(col) = num++;
        } else {
            row += 2;
            col++;
            continue;
        }
        row--;
        col--;
    }
}

// copy constructor
magicsquare::magicsquare(const magicsquare& other) : n_(other.n_) {
    std::cout << "In copy constructor " << other.n_ << std::endl;
    matrix_ = new std::vector<std::vector<int>*>(n_);
    for (int i = 0; i < n_; i++) {
        (*matrix_)[i] = new std::vector<int>(*(other.matrix_->at(i)));
    }
}

// copy assignment operator
magicsquare& magicsquare::operator=(const magicsquare& other) {
    std::cout << "In equal operator " << other.n_ << std::endl;

    if(this != &other) {
        for(auto vec : *matrix_) {
            delete vec;
        }
        delete matrix_;

        matrix_ = new std::vector<std::vector<int>*>();
        for(int i = 0; i < other.n_; ++i) {
            matrix_->push_back(new std::vector<int>(*(other.matrix_->at(i))));
        }
    }
    return *this;
}


int magicsquare::getRC(int r, int c) const {
    return (*matrix_)[r]->at(c);
}

//  output assignment operator
std::ostream& operator<<(std::ostream& out, const magicsquare& ms) {
    out << "magic square for n = " << ms.n_ << " sum = " << (ms.n_ * (ms.n_ * ms.n_ + 1)) / 2 << "\n";

    if (ms.n_ <= 11) {
        for (int i = 0; i < ms.n_; ++i) {
            for (int j = 0; j < ms.n_; ++j) {
                out << std::setw(3) << (*ms.matrix_)[i]->at(j) << " ";
            }
            out << "\n";
        }

    }
    out << "----------------------------------";
    return out;
}



// Destructor
magicsquare::~magicsquare() {
    std::cout << "In disconstructor " << n_ << std::endl;
    for (int i = 0; i < n_; i++) {
        delete (*matrix_)[i];
    }
    delete matrix_;
}

