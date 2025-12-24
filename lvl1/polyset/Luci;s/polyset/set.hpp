#include "searchable_bag.hpp"

class set {
    searchable_bag &_bag;
    set();
    public: 
        set(searchable_bag &other);
        set(const set &other);
        const set &operator=(const set &other);
        ~set();
        void insert(int value);
        bool has(int value) const;
        void print();
        searchable_bag &get_bag();
        const searchable_bag &get_bag() const;
        void clear();
        void insert(int *arr, int size);

};