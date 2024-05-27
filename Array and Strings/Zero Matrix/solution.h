#pragma once

#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define ROWS 5
#define COLS 5

void fillMatrix(vector<vector<int>> &M)
{
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            M[i][j] = (double)rand() / RAND_MAX * 10;
        }
    }
}

void set_row_to_0(vector<vector<int>> &M, int row)
{
    for (int i = 0; i < COLS; i++)
        M[row][i] = 0;
}

void set_col_to_0(vector<vector<int>> &M, int col)
{
    for (int i = 0; i < ROWS; i++)
        M[i][col] = 0;
}

void solve(vector<vector<int>> &M)
{
    vector<pair<int, int>> zeros;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (M[i][j] == 0)
                zeros.push_back(make_pair(i, j));
        }
    }

    set<int> ExcludeRows;
    set<int> ExcludeCols;

    for (const auto &zero : zeros)
    {
        int row = zero.first;
        int col = zero.second;

        if (ExcludeRows.find(row) == ExcludeRows.end())
            set_row_to_0(M, row);
        if (ExcludeCols.find(col) == ExcludeCols.end())
            set_col_to_0(M, col);

        ExcludeRows.insert(row);
        ExcludeCols.insert(col);
    }
}

void printMatrix(vector<vector<int>> &M)
{
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

int test()
{
    srand(time(nullptr));

    vector<vector<int>> M;
    M.resize(ROWS, vector<int>(COLS));
    fillMatrix(M);
    printMatrix(M);
    solve(M);
    cout << endl;
    printMatrix(M);

    return 0;
}