// #pragma once

#include "array_bag.hpp"
#include "searchable_bag.hpp"

class searchable_array_bag : public array_bag, public searchable_bag {
public:
	// Orthodox canonical form
	searchable_array_bag();
	searchable_array_bag(const searchable_array_bag &);
	searchable_array_bag &operator=(const searchable_array_bag &);
	~searchable_array_bag();

	// searchable_bag API
	bool has(int) const;
};
