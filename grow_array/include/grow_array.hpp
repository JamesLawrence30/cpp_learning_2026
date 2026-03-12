namespace jim {
    class grow_array {
        int size_;
        int capacity_;
        int* container;

    public:
        grow_array();
        ~grow_array();

        grow_array(const grow_array& other); // creating new object from existing
        grow_array(grow_array&& other) noexcept; // steal buffer from other and reset other

        grow_array& operator=(const grow_array& other); // overwrite existing object with deep copy of another
        grow_array& operator=(grow_array&& other) noexcept; // transfer ownership of resources from another object

        int& operator[](int i); // modify
        const int& operator[](int i) const; // read-only

        void push_back(int n);

        int size() const;
        void stats() const;
        void print() const;
    };
};