/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: intmatrix2.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has intmatrix2 class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
NOTHING CAM BE ADDED except intmatrix2.h
-----------------------------------------------------------------*/
#include "intmatrix2.h"

/*----------------------------------------------------------------
Definition of routines of intmatrix2 class
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
Space allocation of static must be in CPP file
-----------------------------------------------------------------*/
bool intmatrix2::_show = false ;


/*----------------------------------------------------------------
WRITE CODE BELOW
-----------------------------------------------------------------*/
// init overloading
intmatrix2::intmatrix2() {
    data_.clear();
    rows_ = 0;
    cols_ = 0;
}

intmatrix2::intmatrix2(int rows, int cols) {
    data_ = std::vector<std::vector<int>>(rows, std::vector<int>(cols, 0));
    rows_ = rows;
    cols_ = cols;
}

intmatrix2::intmatrix2(int rows, int cols, int init_val) {
    if(rows == 0 || cols == 0) {
        data_.clear();
        if(rows==0)
        {
            rows_ = 0;
            cols_ = cols;
        }
        else
        {
            rows_ = rows;
            cols_ = 0;
        }
        return;
    }
    data_ = std::vector<std::vector<int>>(rows, std::vector<int>(cols, init_val));
    rows_ = rows;
    cols_ = cols;
}

intmatrix2::intmatrix2(const std::string& str) {
    std::istringstream iss(str);
    std::string row_str;
    data_.clear();
    rows_ = 0;
    cols_ = 0;

    while (getline(iss, row_str, '|')) {
        std::istringstream row_iss(row_str);
        int val_;
        std::vector<int> row_;

        while (row_iss >> val_) {
            row_.push_back(val_);
        }

        if (!row_.empty()) {
            if (cols_ == 0) {
                cols_ = row_.size();
            } else if (row_.size() != cols_) {
                 // empty matrix
                rows_ = 0;
                cols_ = 0;
                data_ = std::vector<std::vector<int>>(rows_, std::vector<int>(cols_));
                return;
            }

            data_.push_back(row_);
            ++rows_;
        }
    }
}

// output matrix
void intmatrix2::print(const std::string& name) const {
    if (!_show) return;
    std::cout << name << std::endl;
    for (const auto& row : data_) {
        for (const auto& elem : row) {
            std::cout << elem << ' ';
        }
        std::cout << std::endl;
    }
}

// free malloc
void intmatrix2::fini() {
    data_.clear();
}

bool intmatrix2::isEmpty() const {
    return data_.empty();
}

// is equal
bool intmatrix2::isEqual(const intmatrix2& other) const {
    return data_ == other.data_;
}

// matrix add
intmatrix2 intmatrix2::add(const intmatrix2& other) const {
    if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
        return intmatrix2(); // empty matrix
    }

    intmatrix2 result(this->rows_, this->cols_);
    for (int i = 0; i < this->rows_; ++i) {
        for (int j = 0; j < this->cols_; ++j) {
            result.data_[i][j] = this->data_[i][j] + other.data_[i][j];
        }
    }
    return result;
}


// matrix mult
intmatrix2 intmatrix2::mult(const intmatrix2& other) const {
    // check this or other is 1x1 matrix
    if (this->rows_ == 1 && this->cols_ == 1) {
        int scalar = this->data_[0][0];
        intmatrix2 result = other;
        for (int i = 0; i < result.rows_; ++i) {
            for (int j = 0; j < result.cols_; ++j) {
                result.data_[i][j] *= scalar;
            }
        }
        return result;
    } else if (other.rows_ == 1 && other.cols_ == 1) {
        int scalar = other.data_[0][0];
        intmatrix2 result = *this;
        for (int i = 0; i < result.rows_; ++i) {
            for (int j = 0; j < result.cols_; ++j) {
                result.data_[i][j] *= scalar;
            }
        }
        return result;
    }

    if (this->cols_ != other.rows_) {
        return intmatrix2(); // empty matrix
    }

    intmatrix2 result(this->rows_, other.cols_);
    for (int i = 0; i < this->rows_; ++i) {
        for (int j = 0; j < other.cols_; ++j) {
            result.data_[i][j] = 0;
            for (int k = 0; k < this->cols_; ++k) {
                result.data_[i][j] += this->data_[i][k] * other.data_[k][j];
            }
        }
    }
    return result;
}

// Output operator overloading
std::ostream& operator<<(std::ostream& os, const intmatrix2& mat) {
    for (const auto& row : mat.data_) {
        for (const auto& elem : row) {
            os << elem << ' ';
        }
        os << std::endl;
    }
    return os;
}

intmatrix2::operator bool() const {
    return !isEmpty();
}
//EOF

