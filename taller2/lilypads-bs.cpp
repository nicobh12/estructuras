#include <bits/stdc++.h>
#define pb push_back
#define endl '\n'
#define maxn 1200001
using namespace std;

bool v[maxn];

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n;

    int frogs[n + 1];
    int lilypads[maxn];

    for (int i = 1; i <= n; i++)
    {
        int l;
        cin >> l;

        frogs[i] = l;
        v[l] = true;
    }

    int idx = 0;
    for (int i = 1; i < maxn; i++)
    {
        if (v[i])
        {
            continue;
        }

        lilypads[idx] = i;
        idx++;
    }

    cin >> q;

    while (q--)
    {
        int frog;
        cin >> frog;

        int start = frogs[frog];

        int to = binarySearch(0, idx, start, lilypads);
        to = -1 * (to + 1);

        int jump = lilypads[to];

        lilypads[to] = start;

        frogs[frog] = jump;

        cout << jump << endl;
    }

    return 0;
}
