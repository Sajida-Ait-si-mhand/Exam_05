#include "theirset.hpp"
#include "theirsearchable_array_bag.hpp"
#include "theirsearchable_tree_bag.hpp"

// Helper to clone a searchable_bag via dynamic type check
static searchable_bag *clone_searchable_bag(const searchable_bag &src) {
	if (const auto *p = dynamic_cast<const searchable_array_bag *>(&src)) {
		return new searchable_array_bag(*p);
	}
	if (const auto *p = dynamic_cast<const searchable_tree_bag *>(&src)) {
		return new searchable_tree_bag(*p);
	}
	return nullptr;
}

set::set(const searchable_bag &src) : bag_ptr(clone_searchable_bag(src)) {}

set::set(const set &other) : bag_ptr(other.bag_ptr ? clone_searchable_bag(*other.bag_ptr) : nullptr) {}

set &set::operator=(const set &other) {
	if (this != &other) {
		delete bag_ptr;
		bag_ptr = other.bag_ptr ? clone_searchable_bag(*other.bag_ptr) : nullptr;
	}
	return *this;
}

set::~set() {
	delete bag_ptr;
	bag_ptr = nullptr;
}

void set::insert(int value) {
	if (!bag_ptr->has(value)) {
		bag_ptr->insert(value);
	}
}

void set::insert(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		insert(arr[i]);
	}
}

void set::print() const {
	bag_ptr->print();
}

void set::clear() {
	bag_ptr->clear();
}

bool set::has(int v) const {
	return bag_ptr->has(v);
}

const searchable_bag &set::get_bag() const {
	return *bag_ptr;
}
