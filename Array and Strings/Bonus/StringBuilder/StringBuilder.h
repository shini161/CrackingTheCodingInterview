#pragma once

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class StringBuilder
{
private:
    string str;

public:
    StringBuilder()
    {
        str.reserve(128); // Default capacity
    }

    StringBuilder(const string &initialString) : str(initialString)
    {
        str.reserve(initialString.size());
    }

    StringBuilder(int initialCapacity)
    {
        str.reserve(static_cast<unsigned int>(max(0, initialCapacity)));
    }

    void append(const string &s)
    {
        str.append(s);
    }

    void append(const char *s)
    {
        str.append(s);
    }

    void append(char c)
    {
        str.push_back(c);
    }

    void append(const StringBuilder &sb)
    {
        str.append(sb.str);
    }

    void clear()
    {
        str.clear();
    }

    string toString() const
    {
        return str;
    }

    size_t capacity() const
    {
        return str.capacity();
    }

    size_t size() const
    {
        return str.size();
    }

    // Reserve memory
    void reserve(size_t n)
    {
        str.reserve(n);
    }

    void reserve(int n)
    {
        str.reserve(static_cast<unsigned int>(max(0, n)));
    }

    // Overload the += operator for string
    StringBuilder &operator+=(const string &s)
    {
        append(s);
        return *this;
    }

    // Overload the += operator for C string
    StringBuilder &operator+=(const char *s)
    {
        append(s);
        return *this;
    }

    // Overload the += operator for chat
    StringBuilder &operator+=(char c)
    {
        append(c);
        return *this;
    }

    // Overload the += operator for StringBuilder
    StringBuilder &operator+=(const StringBuilder &sb)
    {
        append(sb);
        return *this;
    }

    // Overload the [] operator for accessing chars
    char operator[](size_t index) const
    {
        return str[index];
    }

    // Overload the << operator for ostream
    friend ostream &operator<<(ostream &os, const StringBuilder &sb)
    {
        os << sb.toString();
        return os;
    }
};
