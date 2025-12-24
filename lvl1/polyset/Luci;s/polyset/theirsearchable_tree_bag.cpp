#include "theirsearchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() : tree_bag() {}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &src) : tree_bag(src) {}

searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag &src) {
	if (this != &src) {
		tree_bag::operator=(src);
	}
	return *this;
}

searchable_tree_bag::~searchable_tree_bag() {}

bool searchable_tree_bag::has(int value) const {
	// Traverse BST starting from the protected root pointer `tree`
	node *cursor = this->tree;
	while (cursor != nullptr) {
		if (value < cursor->value) {
			cursor = cursor->l;
		} else if (value > cursor->value) {
			cursor = cursor->r;
		} else {
			return true;
		}
	}
	return false;
}
