#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define maxn 1000001

const string infinite = "zzzzzzzzzzzzzzzz";


void merge(string A[], int start, int half, int end)
{
    int n1 = half - start + 1;
    int n2 = end - half;

    string L[n1 + 1], R[n2 + 1];

    for (int i = 0; i < n1; i++)
    {
        L[i] = A[start + i];
    }

    for (int i = 0; i < n2; i++)
    {
        R[i] = A[half + i + 1];
    }

    L[n1] = infinite;
    R[n2] = infinite;

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

void mergeSort(string A[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(A, start, mid);
        mergeSort(A, mid + 1, end);

        merge(A, start, mid, end);
    }
}

int binarySearch(int start, int end, string x, string A[])
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


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;

    cin >> n >> q;

    string *A = new string[maxn];

    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;

        A[i] = a;
    }

    mergeSort(A, 0, n - 1);

    while (q--)
    {
        string r1, r2;
        cin >> r1 >> r2;

        int l = binarySearch(0, n - 1, r1, A);
        l = (l < 0) ? -1 * (l + 1) : l;

        int r = binarySearch(0, n - 1, r2, A);
        r = (r < 0) ? -1 * (r + 2) : r;

        cout << r - l + 1 << endl;
    }

    return 0;
}