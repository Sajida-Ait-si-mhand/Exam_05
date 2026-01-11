#ifndef SEARCHABLE_TREE_BAG_HPP
#define SEARCHABLE_TREE_BAG_HPP

#include "tree_bag.hpp"
#include "searchable_bag.hpp"

class searchable_tree_bag : public tree_bag, public searchable_bag
{
public:
    searchable_tree_bag() { }; 
    ~searchable_tree_bag() { }; 
    searchable_tree_bag(const searchable_tree_bag &other) : tree_bag(other) {};
    searchable_tree_bag &operator=(const searchable_tree_bag &other)
    {
        if (this != &other)
            tree_bag::operator=(other);
        return *this;
    }
    // looping through the tree had lmra bina nsearchiw f tree ila mal9inash value tanshofo limen wla lisser f tree 

    bool has(int val) const // dont forger the const
    {
        node *current = tree; // matnssynsh t initializing current with tree li kayna tree_bag.hpp 
        while (current)
        {
            if (current->value == val)
                return true;
            else if (val > current->value)
                current = current->r; // right child
            else
                current = current->l; // left child
        }
        return false;
    }
};

#endif