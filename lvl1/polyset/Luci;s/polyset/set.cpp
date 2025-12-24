#include "set.hpp"



set::set(searchable_bag &other) : _bag(other) {}
set::set(const set &other) : _bag(other._bag) {}
const set &set::operator=(const set &other)
{
    if(this != &other)
        _bag = other._bag;
    return *this;
}
set::~set() {}

void set::insert(int value)
{
    if (_bag.has(value) == false)
        _bag.insert(value);
}

 bool set::has(int value) const
 {
    return _bag.has(value);
 }
        void set::print()
        {
            _bag.print();
        }
        searchable_bag &set::get_bag()
        {
            return _bag;
        }
    
        const searchable_bag &set::get_bag() const
        {
            return _bag;
        }
        void set::clear()
        {
            _bag.clear();
        }
        void set::insert(int *arr, int size)
        {
            for (int i = 0; i < size; ++i)
            {
                if (_bag.has(arr[i]) == false)
                    _bag.insert(arr[i]);
            }
        }

