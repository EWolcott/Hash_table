
#ifndef PAIR_H
#define PAIR_H

template <typename Type>
struct pair
{
    std::string first;
    Type second;
    pair(const std::string &x, const Type &y) : first(x), second(y) {}
    pair() : first(""), second(Type()) {}
    pair(const pair &other)
    {
        first = other.first;
        second = other.second;
    }
};

#endif