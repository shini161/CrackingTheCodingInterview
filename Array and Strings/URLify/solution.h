#include <iostream>

using namespace std;

void solve(char str[], int length)
{
    int spaceCount = 0;
    for (int i = 0; i < length; ++i)
    {
        if (str[i] == ' ')
            ++spaceCount;
    }

    int newIndex = length - 1 + spaceCount * 2;
    str[newIndex + 1] = '\0'; // Terminates the string

    /*
    This loop, iterates through the original string from right to left
    when a character is encountered it places it at the end of the new sized string (but in-place) and decrements newIndex
    when a space is encountered it just adds %20 from right and decrements newIndex by 3
    */
    for (int i = length - 1; i >= 0; --i)
    {
        if (str[i] == ' ')
        {
            str[newIndex] = '0';
            str[newIndex - 1] = '2';
            str[newIndex - 2] = '%';
            newIndex -= 3;
        }
        else
        {
            str[newIndex] = str[i];
            --newIndex;
        }
    }
}

int test()
{
    char str[] = "Mr John Smith    ";
    int length = 13;

    solve(str, length);

    cout << str << endl; // Output: Mr%20%John%
    return 0;
}