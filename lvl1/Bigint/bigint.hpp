#pragma once

#include <iostream>
#include <cstdlib>
#include <string>

class bigint
{
	std::string digits;
	public:
		bigint(unsigned long n = 0)
		{
			if(n == 0)
				digits = "0";
			else
			{
				while (n> 0 )
				{
					digits.push_back((n % 10) + '0');
					n /= 10;
				}
				
			}
		}
		bigint(const std::string& n)
		{
			std::string res =n;
			std::reverse(digits.begin() ,digits.end());

			while (digits.length() > 1 && digits.back() == '0')
			{
				digits.pop_back();
			}
			if(digits.empty())
				digits = "0";
			
			
		}
		bigint(const bigint& other) : digits(other.digits){}
		bigint& operator=(const bigint& other) 
		{
			if(this != &other)
			{
				digits = other.digits;
			}
			return *this;
		}
		bigint& operator+=(const bigint& other) 
		{
			int carry = 0;
			std::string res;
			for(size_t i = 0; i< digits.length() || i< other.digits.length()|| carry; ++i)
			{
				int d1 = i < digits.length()? digits[i] - '0' : 0;
				int d2 = i < other.digits.length()? other.digits[i] - '0' : 0;
				int sum = d1 +d2 + carry;
				res.push_back((sum % 10) +'0' );
				carry = sum / 10;
			}
			digits = res;
			return *this;
		}
		bigint operator+(const bigint& other) const
		{
			return bigint(*this) += other;
		}

		bigint& operator++()
		{
			return *this += bigint(1);
		}
		bigint operator++(int)
		{
			bigint tmp  = *this;
			++(*this);
			return tmp;
		}
		int to_int(const bigint& other) const
		{
			std::string res = other.digits;
			std::reverse(res.begin(), res.end());
			int num  = std::atoi(res.c_str());

			return num;
		}
		bigint& operator<<=(const bigint& other)
		{
			int n = to_int(other);
			if(digits != "0" && n >0)
			{
				digits.insert(0 ,n ,'0');
			}
			return *this;
		}
		bigint operator<<(const bigint& other) const
		{
			return bigint(*this) <<= other;
		}
		bigint& operator>>=(const bigint& other)
		{
			int n = to_int(other);
			if(n > 0)
			{
				if((size_t)n >= digits.length())
					digits = "0";
				else
					digits.erase(0,n);
			}
			if(digits.empty())
				digits = "0";
			return *this ;
		}
		bigint operator>>(const bigint& other) const
		{
			return bigint(*this) >>= other;
		}
		bool operator<(const bigint& other) const
		{
			if(digits.length() != other.digits.length())
				return digits.length() < other.digits.length();
			for( int i = digits.length() - 1  ; i >= 0; --i)
			{
				if(digits[i] != other.digits[i])
					return digits[i] <other.digits[i];

			}
			return false;
		}
		bool operator>=(const bigint& other) const
		{
			return !(*this < other);
		}
		bool operator>(const bigint& other) const
		{
			return other < *this;;
		}
		bool operator<=(const bigint& other) const
		{
			return !(other < *this);
		}
		bool operator==(const bigint& other) const
		{
			return digits == other.digits;
		}
		bool operator!=(const bigint& other) const
		{
			return !(*this == other);
		}

		friend std::ostream& operator<<(std::ostream& os , const bigint& b)
		{
			for(int i = b.digits.length() -1 ; i >= 0; --i)
			{
				os << b.digits[i];
			}
			return os;
		}
};