#ifndef OBJ2_H
#define OBJ2_H

#include <iostream>

class Object2
{
private:
    int key;

public:
    Object2();
    Object2(const int &value) : key(value) {}

    void setObject(int element){
        key=element;
    }

    bool isValid() const {
    // Check if the key value is an integer
    return (key == static_cast<int>(key));
}


    bool operator<(const Object2 &obj) const
    {
        return key < obj.key;
    }

    bool operator<=(const Object2 &obj) const
    {
        return key <= obj.key;
    }

    bool operator>(const Object2 &obj) const
    {
        return key > obj.key;
    }

    bool operator>=(const Object2 &obj) const
    {
        return key >= obj.key;
    }

    bool operator==(const Object2 &obj) const
    {
        return key == obj.key;
    }

    Object2 operator*(int factor) const
    {
        return Object2(key * factor);
    }

    Object2 operator/(int factor) const
    {
        return Object2(key / factor);
    }

    friend std::ostream &operator<<(std::ostream &os, const Object2 &obj)
    {
        os << obj.key;
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Object2 &obj)
    {
        is >> obj.key;
        return is;
    }
};

Object2::Object2()
{
}

#endif