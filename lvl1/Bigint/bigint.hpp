
// #pragma once 

// #include <string>
// #include <iostream>

// class bigint {
// private:
//     std::string digits;
//     std::string addStrings(const std::string& a, const std::string& b) const;
//     void removeLeadingZeros();
//     bool isZero() const;
    
// public:
//     bigint();
//     bigint(unsigned int num);
//     bigint(const std::string& str);
    
//     bigint operator+(const bigint& other) const;
//     bigint& operator+=(const bigint& other);
    
//     bool operator==(const bigint& other) const;
//     bool operator!=(const bigint& other) const;
//     bool operator<(const bigint& other) const;
//     bool operator>(const bigint& other) const;
//     bool operator<=(const bigint& other) const;
//     bool operator>=(const bigint& other) const;
    
//     bigint operator<<(unsigned int shift) const;
//     bigint operator>>(unsigned int shift) const;
//     bigint& operator<<=(unsigned int shift);
//     bigint& operator>>=(unsigned int shift);
    
//     // shift with bigint
//     bigint operator<<(const bigint& shift) const;
//     bigint operator>>(const bigint& shift) const;
//     bigint& operator<<=(const bigint& shift);
//     bigint& operator>>=(const bigint& shift);

//     bigint& operator++();     
//     bigint operator++(int);    
    
//     std::string getDigits() const;
// };
// std::ostream& operator<<(std::ostream& os, const bigint& num);
#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <climits>

class bigint {
private:
    std::string digits;

    std::string addStrings(const std::string& a, const std::string& b) const {
        std::string result;
        int carry = 0;
        size_t len = std::max(a.size(), b.size());
        
        for (size_t i = 0; i < len || carry; ++i) {
            int digitA = i < a.size() ? a[i] - '0' : 0;
            int digitB = i < b.size() ? b[i] - '0' : 0;
            int sum = digitA + digitB + carry;
            result.push_back((sum % 10) + '0');
            carry = sum / 10;
        }
        
        return result;
    }

    void removeLeadingZeros() {
        while (digits.size() > 1 && digits.back() == '0') {
            digits.pop_back();
        }
    }

    bool isZero() const {
        return digits == "0";
    }

    std::string getDigits() const {
        return digits;
    }

public:
    bigint() : digits("0") {}

    bigint(unsigned long long num) {
        if (num == 0) {
            digits = "0";
            return;
        }
        std::ostringstream oss;
        oss << num;
        digits = oss.str();
        std::reverse(digits.begin(), digits.end());
    }

    bigint(const std::string& str) {
        if (str.empty() || !std::all_of(str.begin(), str.end(), ::isdigit)) {
            digits = "0";
        } else {
            digits = str;
            std::reverse(digits.begin(), digits.end());
            removeLeadingZeros();
        }
    }

    bigint operator+(const bigint& other) const {
        bigint result;
        result.digits = addStrings(this->digits, other.digits);
        result.removeLeadingZeros();
        return result;
    }

    bigint& operator+=(const bigint& other) {
        digits = addStrings(this->digits, other.digits);
        removeLeadingZeros();
        return *this;
    }

    bool operator==(const bigint& other) const {
        bigint a = *this, b = other;
        a.removeLeadingZeros();
        b.removeLeadingZeros();
        return a.digits == b.digits;
    }

    bool operator!=(const bigint& other) const {
        return !(*this == other);
    }

    bool operator<(const bigint& other) const {
        bigint a = *this, b = other;
        a.removeLeadingZeros();
        b.removeLeadingZeros();
        
        if (a.digits.size() != b.digits.size())
            return a.digits.size() < b.digits.size();
        
        for (int i = a.digits.size() - 1; i >= 0; --i) {
            if (a.digits[i] != b.digits[i])
                return a.digits[i] < b.digits[i];
        }
        return false;
    }

    bool operator>(const bigint& other) const { 
        return other < *this; 
    }

    bool operator<=(const bigint& other) const { 
        return !(*this > other); 
    }

    bool operator>=(const bigint& other) const { 
        return !(*this < other); 
    }

    bigint operator<<(unsigned int shift) const {
        if (isZero() || shift == 0) return *this;
        
        bigint result = *this;
        result.digits.insert(result.digits.begin(), shift, '0');
        result.removeLeadingZeros();
        return result;
    }

    // bigint operator>>(unsigned int shift) const {
    //     if (shift == 0) return *this;
        
    //     bigint result = *this;
    //     if (shift >= result.digits.size()) 
    //         result.digits = "0";
    //     else 
    //         result.digits.erase(result.digits.begin(), result.digits.begin() + shift);
    //     result.removeLeadingZeros();
    //     return result;
    // }

    bigint operator>>(unsigned int shift) const {
        if (shift == 0) return *this;
        
        bigint result = *this;
        if (shift >= result.digits.size())  // ← BUG HERE!
            result.digits = "0";
        else 
            result.digits.erase(result.digits.begin(), result.digits.begin() + shift);
        result.removeLeadingZeros();
    return result;
}

    bigint& operator<<=(unsigned int shift) {
        *this = *this << shift;
        return *this;
    }

    bigint& operator>>=(unsigned int shift) {
        *this = *this >> shift;
        return *this;
    }

    bigint operator<<(const bigint& shift) const {
        if (shift.isZero()) return *this;
        
        bigint maxShift(UINT_MAX);
        if (shift > maxShift) {
            return *this << UINT_MAX;
        }
        
        std::string reversed = shift.digits;
        std::reverse(reversed.begin(), reversed.end());
        unsigned int shiftAmount = std::stoul(reversed);
        
        return *this << shiftAmount;
    }

    bigint operator>>(const bigint& shift) const {
        if (shift.isZero()) return *this;
        
        bigint maxShift(UINT_MAX);
        if (shift > maxShift) {
            return bigint(0);
        }
        
        std::string reversed = shift.digits;
        std::reverse(reversed.begin(), reversed.end());
        unsigned int shiftAmount = std::stoul(reversed);
        
        return *this >> shiftAmount;
    }

    bigint& operator<<=(const bigint& shift) {
        *this = *this << shift;
        return *this;
    }

    bigint& operator>>=(const bigint& shift) {
        *this = *this >> shift;
        return *this;
    }

    bigint operator++(int) {
        bigint temp = *this;
        *this += bigint(1);
        return temp;
    }

    bigint& operator++() {
        *this += bigint(1);
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const bigint& num) {
        std::string str(num.getDigits());
        std::reverse(str.begin(), str.end());
        os << str;
        return os;
    }
};