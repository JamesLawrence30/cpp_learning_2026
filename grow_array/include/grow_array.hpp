namespace jim {
    class grow_array {
        int size_;
        int capacity_;
        int* container;

    public:
        grow_array();
        ~grow_array();

        int size();
        void push_back(int n);
    };
};