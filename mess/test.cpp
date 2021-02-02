#include <iostream>
#include <algorithm>

const int lens = 10;

int ances[10];

void init()
{
    for (int i = 0; i < 10; i++)
    {
        ances[i] = i;
    }
}

int find(int x)
{
    if (ances[x] != x)
        ances[x] = find(ances[x]);
    return ances[x];
}

int merge(int a, int b)
{
    a = find(a);
    b = find(b);
    ances[b] = a;
}
