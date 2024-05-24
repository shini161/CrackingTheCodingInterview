#pragma once

#include <iostream>
#include <fstream>

using namespace std;

bool solve(string str1, string str2)
{
    if (str1 == str2)
        return true;

    int len1 = str1.size();
    int len2 = str2.size();

    if (abs(len1 - len2) > 1)
        return false;

    int i = 0, j = 0;
    bool foundDifference = false;

    while (i < len1 && j < len2)
    {
        if (str1[i] == str2[j])
        {
            i++;
            j++;
            continue;
        }

        if (foundDifference)
            return false;
        foundDifference = true;

        if (len1 > len2)
            i++;
        else if (len1 < len2)
            j++;
        else
        {
            i++;
            j++;
        }
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