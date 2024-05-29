#include <iostream>
#include <cassert>
#include "StringBuilder.h"

using namespace std;

int main()
{
    // Test default constructor and toString
    StringBuilder sb1;
    assert(sb1.toString() == "");
    cout << "Default constructor test passed." << endl;

    // Test constructor with initial string
    StringBuilder sb2("Hello");
    assert(sb2.toString() == "Hello");
    cout << "Constructor with initial string test passed." << endl;

    // Test constructor with initial capacity
    StringBuilder sb3(256);
    assert(sb3.capacity() >= 256);
    cout << "Constructor with initial capacity test passed." << endl;

    // Test append with std::string
    sb1.append("Hello, ");
    sb1.append("World!");
    assert(sb1.toString() == "Hello, World!");
    cout << "Append with std::string test passed." << endl;

    // Test append with C-style string
    sb1.append(" How are you?");
    assert(sb1.toString() == "Hello, World! How are you?");
    cout << "Append with C-style string test passed." << endl;

    // Test append with single character
    sb1.append(' ');
    sb1.append('I');
    sb1.append(' ');
    sb1.append('a');
    sb1.append('m');
    assert(sb1.toString() == "Hello, World! How are you? I am");
    cout << "Append with single character test passed." << endl;

    // Test append with another StringBuilder
    StringBuilder sb4(" fine.");
    sb1.append(sb4);
    assert(sb1.toString() == "Hello, World! How are you? I am fine.");
    cout << "Append with another StringBuilder test passed." << endl;

    // Test clear method
    sb1.clear();
    assert(sb1.toString() == "");
    cout << "Clear method test passed." << endl;

    // Test reserve method
    sb1.reserve(500);
    assert(sb1.capacity() >= 500);
    cout << "Reserve method test passed." << endl;

    // Test operator+= with std::string
    sb1 += "Hello";
    assert(sb1.toString() == "Hello");
    cout << "Operator+= with std::string test passed." << endl;

    // Test operator+= with C-style string
    sb1 += ", world";
    assert(sb1.toString() == "Hello, world");
    cout << "Operator+= with C-style string test passed." << endl;

    // Test operator+= with single character
    sb1 += '!';
    assert(sb1.toString() == "Hello, world!");
    cout << "Operator+= with single character test passed." << endl;

    // Test operator+= with another StringBuilder
    sb1 += sb4;
    assert(sb1.toString() == "Hello, world! fine.");
    cout << "Operator+= with another StringBuilder test passed." << endl;

    // Test operator[]
    assert(sb1[0] == 'H');
    assert(sb1[7] == 'w');
    assert(sb1[12] == '!');
    cout << "Operator[] test passed." << endl;

    // Test operator<< for ostream
    cout << "Operator<< test output: " << sb1 << endl;

    cout << "All tests passed." << endl;

    return 0;
}
