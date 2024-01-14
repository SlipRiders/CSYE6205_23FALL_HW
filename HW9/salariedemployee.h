//
// Created by 81516 on 2023/11/19.
//

#ifndef HW9_SALARIEDEMPLOYEE_H
#define HW9_SALARIEDEMPLOYEE_H
#include <string>
#include <iostream>
#include <sstream>

class salariedemployee : public employee {
private:
    std::string* company;
    double monthlySalary;

protected:
    void print(std::ostream& os) const override {
        employee::print(os);  // 首先调用基类的print
        os << " " << *company << " " << monthlySalary;
    }
    std::string getAdditionalInfo() const override {
        // 返回派生类特有的额外信息
        std::ostringstream ss;
        ss << employee::getAdditionalInfo()<< " " << *company << " " << monthlySalary;
        return ss.str();
    }

public:
    salariedemployee(const std::string& fn, const std::string& ln, const std::string& ssn, const std::string& comp, double salary)
            : employee(fn, ln, ssn), company(new std::string(comp)), monthlySalary(salary) {
        if (show) {
            std::cout << "In salariedemployee::salariedemployee constructor " << *firstName << " " << *lastName << " " << *socialSecurityNumber << " " << *company << " " << monthlySalary << std::endl;
        }
    }

    // Copy constructor
    salariedemployee(const salariedemployee& other)
            : employee(other), company(new std::string(*other.company)), monthlySalary(other.monthlySalary) {
        if (show) {
            std::cout << "In salariedemployee copy constructor " << *firstName << " " << *lastName << " " << *socialSecurityNumber << " " << *company << " "<< monthlySalary << std::endl;
        }
    }

    // Copy assignment operator
    salariedemployee& operator=(const salariedemployee& other) {
        if (this != &other) {
            employee::operator=(other);
            *company = *other.company;
            monthlySalary = other.monthlySalary;
            if (show) {
                std::cout << "In salariedemployee equal constructor " << *firstName << " " << *lastName << " " << *socialSecurityNumber << " " << *company << " " << monthlySalary << std::endl;
            }
        }
        return *this;
    }

    // Destructor
    virtual ~salariedemployee() {
        if (show) {
            std::cout << "In salariedemployee::~salariedemployee distructor " << *firstName << " " << *lastName << " " << *socialSecurityNumber << " " << *company << " " << monthlySalary << std::endl;
        }
        delete company;
    }
/*
    // Operator<< overload
    friend std::ostream& operator<<(std::ostream& os, const salariedemployee& e) {
        os << static_cast<const employee&>(e) << " " << *e.company << " " << e.monthlySalary;
        return os;
    }*/
};
#endif //HW9_SALARIEDEMPLOYEE_H
