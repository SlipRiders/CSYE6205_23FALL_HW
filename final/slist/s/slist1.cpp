/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
Filename: slist1.cpp
Edit：Xiaoyang chen By CLION
Time：2023/12/9 13:42
-----------------------------------------------------------------*/

#include "slist1.h"
//NOTHING CAN BE ADDED HERE

/*----------------------------------------------------------------
WRITE CODE BELOW
-----------------------------------------------------------------*/
slist1::slist1() : first_(nullptr), last_(nullptr) {}

void slist1::prepend(T data) {
    auto new_node = std::make_unique<node>(data);
    if (!first_) {
        last_ = new_node.get();
    } else {
        new_node->setNext(std::move(first_));
    }
    first_ = std::move(new_node);
}

void slist1::append(T data) {
    auto new_node = std::make_unique<node>(data);
    if (!first_) {
        first_ = std::move(new_node);
        last_ = first_.get();
    } else {
        last_->setNext(std::move(new_node));
        last_ = last_->getNext();
    }
}

size_t slist1::size() const {
    size_t count = 0;
    node* current = first_.get();
    while (current) {
        ++count;
        current = current->getNext();
    }
    return count;
}

// 输出重载
std::ostream& operator<<(std::ostream& os, const slist1& list) {
    node* current = list.first_.get();
    while (current) {
        os << current->getData() << " ";
        current = current->getNext();
    }
    return os;
}

// 节点访问
const T* slist1::operator[](int index) const {
    if (index < 0) return nullptr;
    node* current = first_.get();
    for (int i = 0; i < index; ++i) {
        if (!current) return nullptr;
        current = current->getNext();
    }
    return current ? &(current->getData()) : nullptr;
}

bool slist1::find(T value) const {
    node* current = first_.get();
    while (current) {
        if (current->getData() == value) return true;
        current = current->getNext();
    }
    return false;
}

bool slist1::remove(T value) {
    if (!first_) {
        return false; // 空链表
    }

    if (first_->getData() == value) {
        first_ = std::move(first_->getNextPtr());
        if (first_.get() == nullptr) {
            last_ = nullptr; // 链表变空了
        }
        return true;
    }

    node* current = first_.get();
    while (current->getNextPtr().get() != nullptr) {
        if (current->getNextPtr()->getData() == value) {
            if (current->getNextPtr().get() == last_) {
                last_ = current; // 删除的是最后一个节点
            }
            current->setNext(std::move(current->getNextPtr()->getNextPtr()));
            return true;
        }
        current = current->getNextPtr().get();
    }

    return false; // 没有找到
}

slist1::slist1(const slist1& other) : first_(nullptr), last_(nullptr) {
    node* current = other.first_.get();
    while (current != nullptr) {
        this->append(current->getData());
        current = current->getNext();
    }
}

slist1& slist1::operator=(const slist1& other) {
    if (this != &other) {
        slist1 temp(other);
        std::swap(first_, temp.first_);
        std::swap(last_, temp.last_);
    }
    return *this;
}


bool operator==(const slist1& lhs, const slist1& rhs) {
    node* currentL = lhs.first_.get();
    node* currentR = rhs.first_.get();
    while (currentL != nullptr && currentR != nullptr) {
        if (currentL->getData() != currentR->getData()) {
            return false;
        }
        currentL = currentL->getNext();
        currentR = currentR->getNext();
    }
    return currentL == nullptr && currentR == nullptr;
}

slist1::operator bool() const {
    return first_ != nullptr;
}

bool operator!=(const slist1& lhs, const slist1& rhs) {
    return !(lhs == rhs);
}
