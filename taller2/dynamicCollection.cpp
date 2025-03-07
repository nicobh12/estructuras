#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int maxn = 1e6;

void merge(int *A, int start, int half, int end)
{
    int n1 = half - start + 1;
    int n2 = end - half;

    int L[n1 + 1], R[n2 + 1];

    for (int i = 0; i < n1; i++)
    {
        L[i] = A[start + i];
    }

    for (int i = 0; i < n2; i++)
    {
        R[i] = A[half + i + 1];
    }

    L[n1] = 1e9;
    R[n2] = 1e9;

    int i = 0, j = 0;
    for (int k = start; k < end + 1; k++)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int *A, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(A, start, mid);
        mergeSort(A, mid + 1, end);

        merge(A, start, mid, end);
    }
}

int binarySearch(int start, int end, int x, int *A)
{
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (A[mid] == x)
        {
            return mid;
        }
        else if (A[mid] > x)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return -1 * start - 1;
}

int firstOccurrence(int start, int end, int x, int *A)
{
    int r, r2;
    r = binarySearch(start, end, x, A);

    if (r >= 0)
    {
        r2 = binarySearch(start, r - 1, x, A);

        while (r2 >= 0)
        {
            r = r2;
            r2 = binarySearch(start, r - 1, x, A);
        }
    }

    return r;
}

int lastOccurrence(int start, int end, int x, int *A)
{
    int r, r2;
    r = binarySearch(start, end, x, A);

    if (r >= 0)
    {
        r2 = binarySearch(r + 1, end, x, A);

        while (r2 >= 0)
        {
            r = r2;
            r2 = binarySearch(r + 1, end, x, A);
        }
    }

    return r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A[2 * maxn];

    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    mergeSort(A, 0, n - 1);

    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int k;
            cin >> k;

            if (k > A[n - 1])
            {
                A[n] = k;
                n++;
            }
            else
            {
                int x = firstOccurrence(0, n - 1, k, A);

                if (x < 0)
                {
                    x = -1*(x + 1);
                    A[x] = k;
                }
            }

        }
        else
        {
            int l, r, r1, r2;
            cin >> r1 >> r2;

            l = firstOccurrence(0, n - 1, r1, A);
            r = lastOccurrence(0, n - 1, r2, A);

            l = (l < 0) ? -1 * (l + 1) : l;
            r = (r < 0) ? -1 * (r + 2) : r;

            cout << r - l + 1 << endl;
        }
    }

    return 0;
}