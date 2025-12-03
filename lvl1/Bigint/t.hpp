#pragma once
#include <iostream>
#include <ostream>
#include <string.h>
#include <algorithm>
#include <stdlib.h>

class bigint
{
private:
	std::string data;
	void removeZero()
	{
		while (data.size() > 1 && data.back() == '0')
		{
			data.pop_back();
		}
	}
	bool isZero() const{
		return data == "0";
	}
	std::string addstring(const std::string &a, const std::string &b) const{
		int carry = 0;
		std::string result;
		size_t len = std::max(a.size(), b.size());
		for (int i = 0; i < len || carry;++i)
		{
			int A = (i < a.size()) ?(a[i] - '0') : 0;
			int B = (i < b.size()) ?(b[i] - '0') : 0;
			int sum = A + B + carry;
			result.push_back((sum % 10) + '0');
			carry = (sum / 10); // check this out 
		}
		return result;
	}
public:
	bigint(): data("0") {};
	bigint(unsigned long long num) 
	{
		if (num = 0)
		{
			data = "0";
			return;
		}
		data = std::to_string(num);
		std::reverse(data.begin(), data.end());
	};
	bigint(const std::string &str) 
	{
		if (str.empty())
		{
			data = "0";
			return ;
		}
		data = str;
		std::reverse(data.begin(), data.end());
		removeZero();
	}
	bigint &operator+=(const bigint& other)  
	{
		data = addstring(this->data, other.data);
		removeZero();
		return *this; // check
	}
	bigint operator+(const bigint& other) const{
		bigint res;
		res.data = addstring(this->data, other.data);
		res.removeZero();
		return res; // check 
	}
	bigint operator++(int)
	{
		bigint temp = *this;
		*this += bigint(1);
		return temp;
	}
	bigint &operator++()
	{
		*this += bigint(1);	
		return *this;
	}
	bool operator<(const bigint& other) const{
		bigint a = *this, b = other;
		a.removeZero();
		b.removeZero();
		if(a.data.size() != b.data.size())
			return a.data.size() < b.data.size();
		// diff size
		for (int i = a.data.size() - 1 ; i >= 0; --i)
		{
			if (a.data[i] != b.data[i])
			{
				return a.data[i] < b.data[i];
			}
		}
		return false;
	}
	bool operator>(const bigint&other) const{
		return other < *this;
	}
	
	bool operator<=(const bigint&other) const{
		return !(other > *this);
	}
	bool operator>=(const bigint&other) const{
		return !(other < *this);
	}
	bool operator==(const bigint&other) const{
		bigint a = *this, b = other;
		a.removeZero();
		b.removeZero();
		return (a.data  == b.data);
	}
	bool operator!=(const bigint&other) const{
		return (other  != *this);
	}
};
