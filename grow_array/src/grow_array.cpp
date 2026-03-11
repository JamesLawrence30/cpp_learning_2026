#include "grow_array.hpp"

#include <utility>

using namespace jim;

grow_array::grow_array()
: size_(0),
  capacity_(0),
  container(new int[capacity_])
{}

grow_array::~grow_array() {
    delete[] container;
}

int grow_array::size() {
    return size_;
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