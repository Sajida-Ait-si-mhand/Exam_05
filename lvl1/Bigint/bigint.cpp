#include "bigint.hpp"
// #include <sstream>
// #include <cctype>
// #include <algorithm>

// bigint::bigint() : digits("0") {}

// bigint::bigint(unsigned int num) {
//     if (num == 0) {
//         digits = "0";
//         return;
//     }
//     std::ostringstream oss;
//     oss << num;
//     digits = oss.str();
//     std::reverse(digits.begin(), digits.end());
// }

// bigint::bigint(const std::string& str) {
//     if (str.empty() || !std::all_of(str.begin(), str.end(), ::isdigit)) {
//         digits = "0";
//     } else {
//         digits = str;
//         std::reverse(digits.begin(), digits.end());
//         removeLeadingZeros();
//     }
// }

// std::string bigint::addStrings(const std::string& a, const std::string& b) const {
//     std::string result;
//     int carry = 0;
//     size_t len = std::max(a.size(), b.size());
    
//     for (size_t i = 0; i < len || carry; ++i) {
//         int digitA = i < a.size() ? a[i] - '0' : 0;
//         int digitB = i < b.size() ? b[i] - '0' : 0;
//         int sum = digitA + digitB + carry;
//         result.push_back((sum % 10) + '0');
//         carry = sum / 10;
//     }
    
//     return result;
// }

// void bigint::removeLeadingZeros() {
//     while (digits.size() > 1 && digits.back() == '0') {
//         digits.pop_back();
//     }
// }

// bigint bigint::operator+(const bigint& other) const {
//     bigint result;
//     result.digits = addStrings(this->digits, other.digits);
//     result.removeLeadingZeros();
//     return result;
// }

// bigint& bigint::operator+=(const bigint& other) {
//     digits = addStrings(this->digits, other.digits);
//     removeLeadingZeros();
//     return *this;
// }

// bool bigint::isZero() const {
//     return digits == "0";
// }

// bool bigint::operator==(const bigint& other) const {
//     bigint a = *this, b = other;
//     a.removeLeadingZeros();
//     b.removeLeadingZeros();
//     return a.digits == b.digits;
// }

// bool bigint::operator!=(const bigint& other) const {
//     return !(*this == other);
// }

// bool bigint::operator<(const bigint& other) const {
//     bigint a = *this, b = other;
//     a.removeLeadingZeros();
//     b.removeLeadingZeros();
    
//     if (a.digits.size() != b.digits.size())
//         return a.digits.size() < b.digits.size();
    
//     for (int i = a.digits.size() - 1; i >= 0; --i) {
//         if (a.digits[i] != b.digits[i])
//             return a.digits[i] < b.digits[i];
//     }
//     return false;
// }

// bool bigint::operator>(const bigint& other) const { 
//     return other < *this; 
// }

// bool bigint::operator<=(const bigint& other) const { 
//     return !(*this > other); 
// }

// bool bigint::operator>=(const bigint& other) const { 
//     return !(*this < other); 
// }

// bigint bigint::operator<<(unsigned int shift) const {
//     if (isZero() || shift == 0) return *this;
    
//     bigint result = *this;
//     result.digits.insert(result.digits.begin(), shift, '0');
//     result.removeLeadingZeros();
//     return result;
// }

// bigint bigint::operator>>(unsigned int shift) const {
//     if (shift == 0) return *this;
    
//     bigint result = *this;
//     if (shift >= result.digits.size()) 
//         result.digits = "0";
//     else 
//         result.digits.erase(result.digits.begin(), result.digits.begin() + shift);
//     result.removeLeadingZeros();
//     return result;
// }

// bigint& bigint::operator<<=(unsigned int shift) {
//     *this = *this << shift;
//     return *this;
// }

// bigint& bigint::operator>>=(unsigned int shift) {
//     *this = *this >> shift;
//     return *this;
// }

// std::string bigint::getDigits() const {
//     return digits;
// }

// std::ostream& operator<<(std::ostream& os, const bigint& num) {
//     std::string str(num.getDigits());
//     std::reverse(str.begin(), str.end());
//     os << str;
//     return os;
// }

// bigint bigint::operator++(int) {
//     bigint temp = *this;
//     *this += bigint(1);
//     return temp;
// }

// bigint& bigint::operator++() {
//     *this += bigint(1);
//     return *this;
// }
// // Add to your .cpp file:

// bigint bigint::operator<<(const bigint& shift) const {
//     // Convert bigint shift to unsigned int
//     if (shift.isZero()) return *this;
    
//     // Check if shift is too large
//     bigint maxShift(UINT_MAX);
//     if (shift > maxShift) {
//         // Shift is too large, could throw or handle differently
//         // For now, just use UINT_MAX as the shift amount
//         return *this << UINT_MAX;
//     }
    
//     // Convert shifted digits to unsigned int
//     std::string reversed = shift.digits;
//     std::reverse(reversed.begin(), reversed.end());
//     unsigned int shiftAmount = std::stoul(reversed);
    
//     return *this << shiftAmount;
// }

// bigint bigint::operator>>(const bigint& shift) const {
//     if (shift.isZero()) return *this;
    
//     bigint maxShift(UINT_MAX);
//     if (shift > maxShift) {
//         // Shifting right by a huge amount = 0
//         return bigint(0);
//     }
    
//     std::string reversed = shift.digits;
//     std::reverse(reversed.begin(), reversed.end());
//     unsigned int shiftAmount = std::stoul(reversed);
    
//     return *this >> shiftAmount;
// }

// bigint& bigint::operator<<=(const bigint& shift) {
//     *this = *this << shift;
//     return *this;
// }

// bigint& bigint::operator>>=(const bigint& shift) {
//     *this = *this >> shift;
//     return *this;
// }