#include <iostream>
#include <stdexcept>

template <typename T>
class generic_grow_array {

    int capacity_;
    int size_;
    T* container_;

public:
    generic_grow_array()
    :
    capacity_(0),
    size_(0),
    container_(nullptr)
    {}
    
    ~generic_grow_array() {
        delete[] container_;
    }

    generic_grow_array(const generic_grow_array& other)
    :
    capacity_(other.capacity_),
    size_(other.size_),
    container_((other.size() == 0) ? nullptr : new T[other.capacity_])
    {
        for (int i=0; i < other.size_; i++) {
            container_[i] = other.container_[i];
        }
    }

    generic_grow_array(generic_grow_array&& other)
    :
    capacity_(other.capacity_),
    size_(other.size_),
    container_(other.container_)
    {
        other.container_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }

    generic_grow_array& operator=(const generic_grow_array& other) {
        if (&other == this) {
            return *this;
        }

        T* temp = (other.capacity_ == 0) ? nullptr : new T[other.capacity_];
        for (int i=0; i<other.size_; i++) {
            temp[i] = other.container_[i];
        }

        delete[] container_;
        container_ = temp;
        capacity_ = other.capacity_;
        size_ = other.size_;

        return *this;
    }

    generic_grow_array& operator=(generic_grow_array&& other) {
        if (&other == this) {
            return *this;
        }

        delete[] container_;
        container_ = other.container_;
        capacity_ = other.capacity_;
        size_ = other.size_;

        other.container_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;

        return *this;
    }

    void push_back(const T& val) {
        if (size_==capacity_) {
            int new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
            
            T* temp = new T[new_capacity];
            for (int i=0; i<size_; i++) {
                temp[i] = container_[i];
            }

            delete[] container_;
            container_ = temp;
            capacity_ = new_capacity;
        }

        container_[size_] = val;
        size_++;
    }

    T& operator[](int i) {
        if (i < 0 || i >= size_)
            throw std::out_of_range("Out of range");
        else
            return container_[i];
    }

    const T& operator[](int i) const {
        if (i < 0 || i >= size_)
            throw std::out_of_range("Out of range");
        else
            return container_[i];
    }

    int size() const {
        return size_;
    }

    void stats() const {
        std::cout << "size=" << size_ << " capacity=" << capacity_ << std::endl;
    }

    void print() {
        for (int i=0; i<size_; i++) {
            std::cout << container_[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    generic_grow_array<int> a;

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

    generic_grow_array<int> b = a;
    b.print();

    generic_grow_array<int> c{};
    c = b;
    c.print();

    generic_grow_array<int> d = std::move(a);
    d.print();

    generic_grow_array<int> e{};
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
