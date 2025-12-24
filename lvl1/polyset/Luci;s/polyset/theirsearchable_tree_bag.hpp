#pragma once

#include "tree_bag.hpp"
#include "searchable_bag.hpp"

class searchable_tree_bag : public tree_bag, public searchable_bag {
public:
	// Orthodox canonical form
	searchable_tree_bag();
	searchable_tree_bag(const searchable_tree_bag &);
	searchable_tree_bag &operator=(const searchable_tree_bag &);
	~searchable_tree_bag();

	// searchable_bag API
	bool has(int) const;
};
