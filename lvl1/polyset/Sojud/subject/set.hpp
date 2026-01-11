#ifndef SET_HPP
#define SET_HPP
#include "searchable_array_bag.hpp"
#include "searchable_tree_bag.hpp"

class set
{
private:
    searchable_bag &bag; // matnsx reference hnaa 

public:
    set(searchable_bag &other) : bag(other) {}; 
    ~set() { bag.clear(); }
    void insert(int val)
    {
        if (!bag.has(val))
            bag.insert(val);
    }
    void insert(int *arr, int size) // insert array of ints nfss lblan dyal insert(int val) ghit tat loopi
    {
        for (int i = 0; i < size; i++)
        {
            if (!bag.has(arr[i]))
                bag.insert(arr[i]);
        }
    }
    bool has(int val) const // dont forget const w t implimenti hadii hyt rah pure virtual wakha maynash f bag.hpp
    {
        return bag.has(val);
    }
    void print() const // dont forget const
    {
        bag.print();
    }
    searchable_bag &get_bag() const // again matnsax const f getter hnaa 
    {
        return bag;
    }
    void clear() const // same here
    {
        bag.clear();
    }
};

#endif