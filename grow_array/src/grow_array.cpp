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

grow_array::grow_array(const grow_array& other)
: size_(other.size_),
  capacity_(other.capacity_),
  container((other.capacity_ == 0) ? nullptr : new int[other.capacity_])
{
    for (int i=0; i < size_; i++) {
        container[i] = other.container[i];
    }

    std::cout << "Copy constructor called" << std::endl;
}

grow_array::grow_array(grow_array&& other) noexcept
: size_(other.size_),
  capacity_(other.capacity_),
  container(other.container)
{
    other.size_ = 0;
    other.capacity_ = 0;
    other.container = nullptr;

    std::cout << "Move constructor called" << std::endl;
}

grow_array& grow_array::operator=(const grow_array& other) {
    std::cout << "Copy assignment called" << std::endl;

    if (&other == this)
        return *this;

    int* old = container;
    int* temp = (other.capacity_ == 0) ? nullptr : new int[other.capacity_];

    for (int i=0; i < other.size_; i++) {
        temp[i] = other.container[i];
    }

    delete[] old;
    container=temp;
    capacity_=other.capacity_;
    size_=other.size_;

    return *this;
}

grow_array& grow_array::operator=(grow_array&& other) noexcept {
    std::cout << "Move assignment called" << std::endl;

    if (&other == this)
        return *this;
    
    delete[] container;
    size_=other.size_;
    capacity_=other.capacity_;
    container=other.container;

    other.size_=0;
    other.capacity_=0;
    other.container=nullptr;

    return *this;
}

grow_array::~grow_array() {
    std::cout << "Destructor called" << std::endl;
    delete[] container;
}

void grow_array::push_back(int n) {
    if (size_ == capacity_) {
        int new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
    
        int* temp = new int[new_capacity];
        for (int i=0; i < size_; i++) {
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
    if (i < 0 || i >= size_) {
        throw std::out_of_range("Out of range");
    }
    return container[i];
}
const int& grow_array::operator[](int i) const {
    if (i < 0 || i >= size_) {
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
    for (int i=0; i < size_; i++) {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;
}