#include <iostream>
#include <fstream>
#include <cctype>
#include <unordered_map>

using namespace std;

void convertToLowerCase(string *str)
{
    for (char &c : *str)
    {
        if (isupper(c))
        {
            c += ('a' - 'A');
        }
    }
}

bool solve(string str)
{
    unordered_map<char, int> hashMap;

    for (char c : str)
    {
        if (!isalpha(c))
            continue;
        hashMap[c]++;
    }

    int oddCount = 0;

    for (const auto &pair : hashMap)
    {
        if (pair.second % 2 == 0)
            continue;
        ++oddCount;
        if (oddCount > 1)
            break;
    }

    return oddCount <= 1;
}

int test()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int T;
    cin >> T;

    cin.ignore();

    for (int test = 1; test <= T; ++test)
    {
        string str;
        getline(cin, str);

        if (str.empty())
        {
            --test;
            continue;
        }

        convertToLowerCase(&str);

        cout << "Case #" << test << ": ";
        cout << solve(str) << endl;
    }
    return 0;
}