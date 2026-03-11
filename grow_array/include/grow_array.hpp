namespace jim {
    class grow_array {
        int size_;
        int capacity_;
        int* container;

    public:
        grow_array();
        ~grow_array();

        void push_back(int n);

        int& operator[](int i);

        int size() const;
        void stats() const;
        void print() const;
    };
};