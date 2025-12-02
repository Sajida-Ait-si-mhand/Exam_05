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
