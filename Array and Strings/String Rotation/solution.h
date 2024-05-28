#pragma once

#include <iostream>
#include <fstream>

using namespace std;

bool isSubstring(string sub, string str)
{
    if (sub.size() > str.size())
        return false;

    for (size_t i = 0; i <= str.size() - sub.size(); i++)
    {
        bool found = true;
        for (size_t j = 0; j < sub.size(); j++)
        {
            if (sub[j] != str[i + j])
            {
                found = false;
                break;
            }
        }
        if (found)
            return true;
    }

    return false;
}

bool solve(string s1, string s2)
{
    if (s1.size() != s2.size() || s1.empty() || s2.empty())
        return false;

    s1 += s1;

    return isSubstring(s2, s1);
}

int test()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int T;
    cin >> T;

    for (int test = 1; test <= T; ++test)
    {
        string s1, s2;
        cin >> s1;
        cin >> s2;

        cout << "Case #" << test << ": ";
        cout << solve(s1, s2) << endl;
    }
    return 0;
}