#pragma once

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool solve(string str1, string str2)
{
    if (str1.size() != str2.size())
        return false;

    unordered_map<char, int> hashMap;

    for (char c : str1)
    {
        hashMap[c]++;
    }

    for (char c : str2)
    {
        hashMap[c]--;
        if (hashMap[c] < 0)
            return false;
    }

    for (const auto &pair : hashMap)
    {
        if (pair.second != 0)
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

    for (int test = 1; test <= T; ++test)
    {
        string str1, str2;
        cin >> str1;
        cin >> str2;

        cout << "Case #" << test << ": ";
        cout << solve(str1, str2) << endl;
    }
    return 0;
}