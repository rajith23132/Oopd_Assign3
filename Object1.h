#ifndef OBJ1_H
#define OBJ1_H

#include <iostream>

class Object1
{
private:
    int key;

public:
    Object1();
    Object1(const int &value) : key(value) {}

    void setObject(int element){
        key=element;
    }

     bool isValid() const {
    // Check if the key value is an integer
    return (key == static_cast<int>(key));
}

    bool operator<(const Object1 &obj) const
    {
        return key < obj.key;
    }

    bool operator<=(const Object1 &obj) const
    {
        return key <= obj.key;
    }

    bool operator>(const Object1 &obj) const
    {
        return key > obj.key;
    }

    bool operator>=(const Object1 &obj) const
    {
        return key >= obj.key;
    }

    bool operator==(const Object1 &obj) const
    {
        return key == obj.key;
    }

    Object1 operator*(int factor) const
    {
        return Object1(key * factor);
    }

    Object1 operator/(int factor) const
    {
        return Object1(key / factor);
    }

    friend std::ostream &operator<<(std::ostream &os, const Object1 &obj)
    {
        os << obj.key;
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Object1 &obj)
    {
        is >> obj.key;
        return is;
    }
};

Object1::Object1()
{
}

#endif