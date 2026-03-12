#include "grow_array.hpp"

#include <iostream>

int main() {
    jim::grow_array a{};

    a.stats();
    a.push_back(56);
    a.stats();
    a.push_back(92);
    a.stats();
    a.push_back(13);
    a.stats();
    a.push_back(6);
    a.stats();
    a.push_back(134);
    a.stats();
    a.push_back(92);
    a.stats();
    a.push_back(763);
    a.stats();
    a.push_back(10016);
    a.stats();
    a.push_back(0);
    a.stats();

    a.print();
    a[8] = 1;
    a.print();

    jim::grow_array b = a;
    b.print();

    jim::grow_array c{};
    c = b;
    c.print();

    jim::grow_array d = std::move(a);
    d.print();

    jim::grow_array e{};
    e = std::move(b);
    e.print();

    // test 'moved from' objects are still safe to use
    a.print();
    b.stats();

    // test self-assignment
    c = c;
    c.print();
    c = std::move(c);
    c.print();

    return 0;
}