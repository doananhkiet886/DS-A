#include <stdio.h>
#include <conio.h>

void solve(int n, char left, char mid, char right)
{
    if (n == 1)
    {
        printf("%c -> %c\n", left, right);
        return;
    }

    solve(n - 1, left, right, mid);
    solve(1, left, mid, right);
    solve(n - 1, mid, left, right);
}

int main()
{
    solve(5, 'A', 'B', 'C');
    getch();
    return 0;
}