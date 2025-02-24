#include <bits/stdc++.h>
using namespace std;
#define MAXT 1000000

long long int arr[MAXT / 2];

void precalc()
{
    for (long long i = 0; i <= MAXT; i += 2)
    {
        arr[i / 2] = i * i;
    }
}

long long int upperBound(long long int x, long long int start, long long int end, long long int *arr)
{
    long long int mid;

    while (start <= end)
    {
        mid = (start + end) / 2;

        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] < x)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return end;
}

int main()
{
    int t;
    cin >> t;

    precalc();

    while (t--)
    {
        long long int n;
        cin >> n;

        long long int x, y;

        long long int layer = upperBound(n - 1, 0, MAXT / 2, arr) + 1;

        long long int top = (2 * layer) * (2 * layer - 1) + 1;

        long long int start = arr[layer - 1] + 1;

        long long int difTop = (top > n) ? top - n : n - top;

        long long int difStart = n - start;

        if (difStart / 2 < difTop)
        {
            x = (2 * (layer - 1)) - difStart;

            y = -1 * (layer - 1);
        }
        else if (top > n)
        {
            x = -1 * (difTop);
            y = layer - difTop;
        }
        else
        {
            x = difTop;
            y = layer - difTop;
        }

        cout << x << " " << y << endl;
    }

    return 0;
}