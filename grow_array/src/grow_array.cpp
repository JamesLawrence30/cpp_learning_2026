#include "grow_array.hpp"

#include <iostream>
#include <stdexcept>

using namespace jim;

grow_array::grow_array()
: size_(0),
  capacity_(0),
  container(nullptr)
{
    std::cout << "Constructor called" << std::endl;
}

grow_array::~grow_array() {
    std::cout << "Destructor called" << std::endl;
    delete[] container;
}

void grow_array::push_back(int n) {
    if (size_ == capacity_) {
        int new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
    
        int* temp = new int[new_capacity];
        for(int i=0; i < size_; i++) {
            temp[i] = container[i];
        }

        int* old = container;
        container = temp;
        delete[] old;
        capacity_ = new_capacity;
    }

    container[size_] = n;
    size_++;
}

int& grow_array::operator[](int i) {
    if(i >= size_) {
        throw std::out_of_range("Out of range");
    }

    return container[i];
}

int grow_array::size() const {
    return size_;
}

void grow_array::stats() const {
    std::cout << "size=" << size_ << " capacity=" << capacity_ << std::endl;
}

void grow_array::print() const {
    for(int i=0; i<size(); i++) {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;
}