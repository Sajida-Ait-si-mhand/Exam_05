// #pragma once

#include "searchable_bag.hpp"

class set {
private:
	searchable_bag *bag_ptr; // owned pointer

	// disable default construction without a bag
	set();

public:
	// Construct from a searchable_bag by deep-copying through its dynamic type
	explicit set(const searchable_bag &);
	set(const set &);
	set &operator=(const set &);
	~set();

	// Forward bag interface while enforcing set semantics on insert
	void insert(int);
	void insert(int *, int);
	void print() const;
	void clear();
	bool has(int) const;

	// Access underlying bag by reference (non-owning)
	const searchable_bag &get_bag() const;
};
