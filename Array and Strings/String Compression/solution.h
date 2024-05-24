#pragma once

#include <iostream>
#include <fstream>

using namespace std;

string solve(string str)
{
    string compressedString;
    int count = 1;
    char c = str[0];

    for (size_t i = 1; i < str.size(); ++i)
    {
        if (str[i] == c)
        {
            ++count;
            continue;
        }

        compressedString += c + to_string(count);
        c = str[i];
        count = 1;
    }

    compressedString += c + to_string(count);

    return compressedString.size() < str.size() ? compressedString : str;
}

int test()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int T;
    cin >> T;

    for (int test = 1; test <= T; ++test)
    {
        string str;
        cin >> str;

        cout << "Case #" << test << ": ";
        cout << solve(str) << endl;
    }

    return 0;
}