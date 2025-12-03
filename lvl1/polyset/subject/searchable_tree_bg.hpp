#pragma once 
#include "searchable_bag.hpp"
#include "tree_bag.hpp"

class searchable_tree_bg :public tree_bag, public searchable_bag
{

public:
	searchable_tree_bg() = default;
	searchable_tree_bg(const searchable_tree_bg&other) : tree_bag(other) {} ;
	searchable_tree_bg& operator=(const searchable_tree_bg& other)
	{
		if (this != &other)
		{
			tree_bag::operator=(other);
		}
		return *this;
	}
	~searchable_tree_bg()  = default;

	bool has(int val) const{
		node *current = tree;
		while (current)
		{
			if (current->value == val)
				return true;
			else if (val > current->value)
				current = current->r;
			else 
				current = current->l;
		}
		return false;
	}
};

