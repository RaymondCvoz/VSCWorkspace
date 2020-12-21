#include <cstdio>

double f()
{
    return 1 + (-0.5) + (0.5 * 0.5 * (-0.5) * 14) - (1 / 6 * 0.5 * 0.5 * 1.5 * 18);
}

int main()
{
    printf("%.5lf", f());
}