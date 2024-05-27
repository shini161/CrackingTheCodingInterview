#include <stdlib.h>
#include <stdio.h>

void solve(int m[2])
{
    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", m[i]);
    }
}

int main()
{
    int s[3] = {2, 5, 7};
    solve(s);
    return 0;
}