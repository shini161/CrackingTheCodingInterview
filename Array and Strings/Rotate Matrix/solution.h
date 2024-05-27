#pragma once

#include <iostream>

using namespace std;

#define N 5

int M[N][N];

void fillMatrix()
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            M[i][j] = count++;
        }
    }
}

void printMatrix()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

void solve()
{
    for (int i = 0; i < (int)(N / 2); i++)
    {
        for (int j = i; j < N - 1 - i; j++)
        {
            int top_left = M[i][j];
            int top_right = M[j][N - 1 - i];
            int bottom_right = M[N - 1 - i][N - 1 - j];
            int bottom_left = M[N - 1 - j][i];

            // -90°
            // M[j][N - 1 - i] = top_left;
            // M[N - 1 - i][N - 1 - j] = top_right;
            // M[N - 1 - j][i] = bottom_right;
            // M[i][j] = bottom_left;

            // 90°
            M[i][j] = top_right;
            M[j][N - 1 - i] = bottom_right;
            M[N - 1 - i][N - 1 - j] = bottom_left;
            M[N - 1 - j][i] = top_left;
        }
    }
}

int test()
{
    fillMatrix();
    printMatrix();
    solve();
    cout << endl;
    printMatrix();
    return 0;
}