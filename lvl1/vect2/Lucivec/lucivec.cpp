
#include <iostream>

class vect2 {
    int _x;
    int _y;
    public:
        vect2() : _x(0), _y(0) {}
        vect2(int x, int y) : _x(x), _y(y) {}
        vect2(const vect2 &other) : _x(other._x), _y(other._y) {}
        vect2 &operator=(const vect2 &other) {
            if (this != &other)
            {
                _x = other._x;
                _y = other._y;
            }
            return *this;
        }

        // v[]
        int &operator[](int index) {return (index == 0) ? _x : _y;}
        int operator[](int index) const {return (index == 0) ? _x : _y;}


        // n * v
        friend vect2 operator*(int n, vect2 v) {return v * n;}

        // v * n
        vect2 operator*(int n) {return vect2(_x * n, _y * n);}

        // v + n
        vect2 operator+(int n) {return vect2(_x + n, _y + n);}

        // n + v
        friend vect2 operator+(int n, vect2 v) {return v + n;}

        // v1 += v2
        vect2 operator+=(vect2 other) {_x += other._x; _y += other._y; return *this;}

        // v -= n
        vect2 operator-=(int n) {*this = *this + (-n); return *this;}

        // v1 -= v2
        vect2 operator-=(vect2 other) {_x -= other._x; _y -= other._y; return *this;}

        // v1 * v2
        vect2 operator*(vect2 other) {return vect2(_x * other._x, _y  * other._y);}

        // v++
        vect2 operator++(int) {vect2 tmp = *this; *this = *this +  1; return tmp;}

        // ++v
        vect2 &operator++() {_x++; _y++; return *this;}

        // v--
        vect2 operator--(int) {vect2 tmp = *this; *this = *this + (-1); return tmp;}

        // --v
        vect2 &operator--() {_x--; _y--; return *this;}

        // v1 == v2
        bool operator==(vect2 v2) {return (_x == v2._x && _y == v2._y);}

        // v1 != v2
        bool operator!=(vect2 v2) {return !(*this == v2);}

};

std::ostream &operator<<(std::ostream &os, const vect2 &v)
{
        os << "{" << v[0] << ", " << v[1] << "}";
        return os;

}