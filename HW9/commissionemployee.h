//
// Created by 81516 on 2023/11/19.
//

#ifndef HW9_COMMISSIONEMPLOYEE_H
#define HW9_COMMISSIONEMPLOYEE_H
#include <string>
#include <iostream>

class commissionemployee : public employee {
protected:
    std::string* company;
    double commission;

    void print(std::ostream& os) const override {
        employee::print(os);  // 首先调用基类的print
        os << " " << *company << " " << commission;
    }

    std::string getAdditionalInfo() const override {
        // 返回派生类特有的额外信息
        std::ostringstream ss;
        ss << employee::getAdditionalInfo() << " " << *company << " " << commission;
        return ss.str();
    }

    virtual std::string getAdditionalInfo2() const {
        // 基类没有额外信息
        return "";
    }


    virtual void printAssignmentInfo(const employee& other) const {
        if (show) {
            cout << "In commissionemployee equal constructor " << *firstName << " " << *lastName << " " << *socialSecurityNumber<< " " << *company << " " << commission;
            cout <<  getAdditionalInfo2() << endl; // 添加额外信息
        }
    }
public:
    // Constructor
    commissionemployee(const std::string& fn, const std::string& ln, const std::string& ssn, const std::string& comp, double comm)
            : employee(fn, ln, ssn), company(new std::string(comp)), commission(comm) {
        if (show) {
            std::cout << "In commissionemployee::commissionemployee constructor " << *firstName << " " << *lastName << " " << *socialSecurityNumber << " " << *company << " " << commission << std::endl;
        }
    }

    // Copy constructor
    commissionemployee(const commissionemployee& other)
            : employee(other), company(new std::string(*other.company)), commission(other.commission) {
        if (show) {
            std::cout << "In commissionemployee copy constructor " << *firstName << " " << *lastName << " " << *socialSecurityNumber << " " << *company << " " << commission<< std::endl;
        }
    }

    void assign(const employee& other) override {
        // 先调用基类的赋值逻辑
        employee::assign(other);
        // 然后处理派生类特有的赋值逻辑

        const commissionemployee* derived = dynamic_cast<const commissionemployee*>(&other);
        if (derived) {
            *company = *derived->company;
            commission = derived->commission;
        }
        commissionemployee::printAssignmentInfo(other);
    }

    // Assignment operator
    commissionemployee& operator=(const commissionemployee& other) {
        if (this != &other) {
            assign(other);
            //printAssignmentInfo(other);
        }
        return *this;
    }

    // Destructor
    virtual ~commissionemployee() {
        if (show) {
            std::cout << "In commissionemployee::~commissionemployee distructor " << *firstName << " " << *lastName << " " << *socialSecurityNumber << " " << *company << " " << commission<< std::endl;
        }
        delete company;
    }
};


#endif //HW9_COMMISSIONEMPLOYEE_H
