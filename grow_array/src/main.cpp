#include "grow_array.hpp"

#include <iostream>

int main() {
    jim::grow_array arr{};

    arr.stats();
    arr.push_back(56);
    arr.stats();
    arr.push_back(92);
    arr.stats();
    arr.push_back(13);
    arr.stats();
    arr.push_back(6);
    arr.stats();
    arr.push_back(134);
    arr.stats();
    arr.push_back(92);
    arr.stats();
    arr.push_back(763);
    arr.stats();
    arr.push_back(10016);
    arr.stats();
    arr.push_back(0);
    arr.stats();

    arr.print();
    arr[8] = 1;
    arr.print();

    return 1;
}