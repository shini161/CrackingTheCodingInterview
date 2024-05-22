#pragma once

#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>

using namespace std;

// Solved with Sets
/*
bool solve(string str)
{
    set<char> uniqueChars;

    for (char c : str)
    {
        if (uniqueChars.find(c) != uniqueChars.end())
        {
            return false;
        }
        uniqueChars.insert(c);
    }

    return true;
}
*/

// Solved without additional structures
bool solve(string str)
{
    sort(str.begin(), str.end());

    for (size_t i = 1; i < str.size(); i++)
    {
        if (str[i] == str[i - 1])
            return false;
    }
    return true;
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

        cout << "Case #" << test << ": ";
        cout << solve(str) << endl;
    }
    return 0;
}