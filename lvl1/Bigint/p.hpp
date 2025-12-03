#pragma once 

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ostream>

// 3 orh
// 4 (2++ const &) (2. + const, &)
// 8 comparaisong const
// 4 shifting int 
// 4  shifting bigint const 
// friend std::ostream &operator(const bigint& oss) 
// std::string getDigit() const
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
		bool isZero() const
		{
			return data == "0";
		}
		std::string Addstring(const std::string &a, const std::string &b) const
		{
			std::string result;
			int carry = 0;
			size_t len = std::max(a.size(), b.size());

			for (size_t i = 0; i < len || carry; i++)
			{
				int A = (i < a.size() ? (a[i] - '0') : 0);
				int B = (i < b.size() ? (b[i] - '0') : 0);
				int sum = A + B + carry;
				result.push_back((sum % 10) + '0');
				carry = sum / 10;
			}
			
		}
		
	public:
		bigint() : data("0"){};
		// from number to string than revers it 
		bigint(unsigned long long num)  { 
			if (num == 0)
			{
				data  = "0";
				return ;
			}
			// convert it 
			data = std::to_string(num);
			// reverese it 
			std::reverse(data.begin(), data.end());
		};
		// reveres it 
		bigint(const std::string &str) {
			if (str.empty())
			{
				data = "0";
				return ;
			}else{
			data = str;
			std::reverse(data.begin(), data.end());
			removeZero();
			}
		};

		bigint operator+(const bigint& other) const{
			bigint result;
			result.Addstring(this->data, other.data);
			result.removeZero();
			return result;
		};
		bigint& operator+=(const bigint& other) {
			data = Addstring(this->data, other.data);
			removeZero();
			return *this;
		};
	
		bool operator<(const bigint& other) const
		{
			bigint a = *this, b = other;
			a.removeZero();
			b.removeZero();
			// same soze 
			if (a.data.size() != b.data.size())
				return a.data.size() < b.data.size();
			// diff size
			for (int i = a.data.size() - 1; i >= 0; --i)
			{
				if (a.data[i] != b.data[i])
				{
					a.data[i] < b.data[i];
				}
			}
			return false;
		}
		bool operator> (const bigint& other) const {
			return other < *this;
		}
		bool operator>=(const bigint& other) const {
			return !(*this < other);
		}
		bool operator<=(const bigint& other) const {
			return !(*this > other);
		}
		bool operator!=(const bigint& other) const {
			return !(*this == other);
		}
		bool operator==(const bigint& other) const {
			bigint a = *this, b = other;
			a.removeZero();
			b.removeZero();
			return a.data == b.data;
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

		// imce
		// 8 shiting 
		// frind 
		// getdata

	
};

