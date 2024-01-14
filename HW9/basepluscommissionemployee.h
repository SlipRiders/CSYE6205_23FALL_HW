//
// Created by 81516 on 2023/11/19.
//
#ifndef HW9_BASEPLUSCOMMISSIONEMPLOYEE_H
#define HW9_BASEPLUSCOMMISSIONEMPLOYEE_H

#include "commissionemployee.h" // Include the parent class header
#include <string>
#include <iostream>

class basepluscommissionemployee : public commissionemployee {
private:
    std::string* department;
    double baseSalary;

protected:
    void print(std::ostream& os) const override {
        //employee::print(os);  // 首先调用基类的print
        commissionemployee::print(os);
        os << " " << *department << " " << baseSalary;
    }
    std::string getAdditionalInfo() const override {
        // 返回派生类特有的额外信息
        std::ostringstream ss;
        ss << commissionemployee::getAdditionalInfo()<<" " << *department << " " << baseSalary;
        return ss.str();
    }

    std::string getAdditionalInfo2() const override {
        // 返回派生类特有的额外信息
        std::ostringstream ss;
        ss << commissionemployee::getAdditionalInfo2()<<" " << *department << " " << baseSalary;
        return ss.str();
    }
     void printAssignmentInfo(const employee& other) const {
        if (show) {
            cout << "In basepluscommissionemployee equal constructor " << *firstName << " " << *lastName << " " << *socialSecurityNumber << " " << *company << " " <<commission<<" " << *department << " " << baseSalary<<endl;
            //cout << getAdditionalInfo() << endl; // 添加额外信息
        }
    }

public:
    // Constructor
    basepluscommissionemployee(const std::string& fn, const std::string& ln, const std::string& ssn, const std::string& comp, double comm, const std::string& dept, double baseSal)
            : commissionemployee(fn, ln, ssn, comp, comm), department(new std::string(dept)), baseSalary(baseSal) {
        if (show) {
            std::cout << "In basepluscommissionemployee::basepluscommissionemployee constructor " << *firstName << " " << *lastName << " " << *socialSecurityNumber << " " << *company << " " << commission << " " << *department << " " << baseSalary << std::endl;
        }
    }

    // Copy constructor
    basepluscommissionemployee(const basepluscommissionemployee& other)
            : commissionemployee(other), department(new std::string(*other.department)), baseSalary(other.baseSalary) {
        if (show) {
            std::cout << "In basepluscommissionemployee copy constructor " << *firstName << " " << *lastName << " " << *socialSecurityNumber << " " << *company << " " << commission << " " << *department << " " << baseSalary << std::endl;
        }
    }

    void assign(const employee& other) override {
        // 先调用基类的赋值逻辑
        commissionemployee::assign(other);
        // 然后处理派生类特有的赋值逻辑

        const basepluscommissionemployee* derived = dynamic_cast<const basepluscommissionemployee*>(&other);
        if (derived) {
            *department = *derived->department;
            baseSalary = derived->baseSalary;
        }
        basepluscommissionemployee::printAssignmentInfo(other);
    }
    // Copy assignment operator
    basepluscommissionemployee& operator=(const basepluscommissionemployee& other) {
        if (this != &other) {
            assign(other);
        }
        return *this;
    }

    // Destructor
    virtual ~basepluscommissionemployee() {
        if (show) {
            std::cout << "In basepluscommissionemployee::~basepluscommissionemployee distructor " << *firstName << " " << *lastName << " " << *socialSecurityNumber << " " << *company << " " << commission << " " << *department << " " << baseSalary << std::endl;
        }
        delete department;
    }
/*
    // Operator<< overload
    friend std::ostream& operator<<(std::ostream& os, const basepluscommissionemployee& e) {
        os << static_cast<const commissionemployee&>(e) << " " << *e.department << " " << e.baseSalary;
        return os;
    }*/
};

#endif //HW9_BASEPLUSCOMMISSIONEMPLOYEE_H

