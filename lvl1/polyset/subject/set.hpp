#pragma once 
#include "searchable_array_bag.hpp"
#include "searchable_bag.hpp"
#include "searchable_tree_bg.hpp"


class set
{
private:
	searchable_bag &bag;
public:
	set(searchable_bag &other) : bag(other) {};
	~set(){
		bag.clear();
	};
	void insert(int val) {
		if (!bag.has(val))
			bag.insert(val);
	}
	void insert(int *arr, int size)
	{
		for (int i = 0; i < size; i++)
		{
			if (!bag.has(arr[i]))
				bag.insert(arr[i]);
		}
	}
	void print() const 
	{
		bag.print();
	}
	void clear()
	{
		bag.clear();
	}
	searchable_bag &get_bag() const{
		return bag;
	}
	bool has(int val) const
	{
		return bag.has(val);
	}
};
