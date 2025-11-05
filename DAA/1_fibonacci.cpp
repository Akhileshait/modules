#include <bits/stdc++.h>
using namespace std;

void fibo(int n)
{
    int a = 0, b = 1;
    cout << a << " " << b << " ";
    int step = 0;

    for (int i = 0; i < n - 2; ++i)
    {
        int c = a + b;
        cout << c << " ";
        a = b;
        b = c;
        step++;
    }
    cout << endl;
    cout << step << endl;
}

int fibo_rec(int n, int &step)
{
    step++;
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibo_rec(n - 1, step) + fibo_rec(n - 2, step);
}

int main()
{
    int n;
    cin >> n;
    fibo(n);
    int step = 0;
    for (int i = 0; i < n; ++i)
    {
        fibo_rec(i, step);
    }
    cout << step << endl;
}