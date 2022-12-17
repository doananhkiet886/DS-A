#include <stdio.h>

int fibonacci_recur(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }

    return fibonacci_recur(n - 1) + fibonacci_recur(n - 2);
}

int fibonacci_loop(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (i == 1 || i == 2)
        {
            return 1;
        }
        else
        {
            return fibonacci_loop(n-1) + fibonacci_loop(n-2);
        }
    }
}

int main()
{
    int fibonacci_n = fibonacci_loop(4);
    printf("%d\n", fibonacci_n);
    return 0;
}