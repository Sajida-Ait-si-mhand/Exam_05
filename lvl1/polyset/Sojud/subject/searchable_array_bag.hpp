#ifndef SEARCHEABLE_ARRAY_BAG_HPP
#define SEARCHEABLE_ARRAY_BAG_HPP 

#include "array_bag.hpp"
#include "searchable_bag.hpp"

class searchable_array_bag : public array_bag, public searchable_bag
{
    public:
        searchable_array_bag(){ };
        ~searchable_array_bag() { };
        searchable_array_bag(const searchable_array_bag &other) : array_bag(other){};
        searchable_array_bag &operator=(const searchable_array_bag &other)
        {
            if (this != &other)
                array_bag::operator=(other);
            return *this;
        }
        //looping through the array to check if the value exists (this class only works with array)
        bool has(int val) const {
            for (int i = 0; i < size; i++)
            { // remember is data not array (check the array_bag.hpp)
                if (data[i] == val)
                    return true;
            }
            return false;
        }
};
#endif