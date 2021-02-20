#include <iostream>
#include <algorithm>

const int lens = 1e6 + 1;
int ances[lens];

int find(int x)
{
    if (ances[x] != x)
    {
        ances[x] = find(ances[x]);
    }
    return ances[x];
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    ances[a] = b;
}
int main()
{
    int x;
    while (ances[x] != x)
    {
        ances[x] = ances[ances[x]];
    }
}