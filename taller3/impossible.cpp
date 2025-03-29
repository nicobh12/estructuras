#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define infinite 2e9
#define ll long long

void minHeapify(ll *Q, ll i, ll size)
{
    ll l, r, min = i;

    l = 2 * i + 1;
    r = 2 * i + 2;

    if (l < size && Q[l] < Q[min])
    {
        min = l;
    }

    if (r < size && Q[r] < Q[min])
    {
        min = r;
    }

    if (min != i)
    {
        swap(Q[i], Q[min]);

        minHeapify(Q, min, size);
    }
}

void buildHeap(ll *Q, ll size)
{
    ll lastParentLeaf = (size / 2) - 1;

    for (ll i = lastParentLeaf; i >= 0; i--)
    {
        minHeapify(Q, i, size);
    }
}

ll minPQ_minimum(ll *Q, ll size)
{
    return Q[0];
}

ll minPQ_extract(ll *Q, ll &size)
{
    ll min = -1 * infinite;
    if (size < 1)
    {
        exit(1);
    }
    else
    {
        min = Q[0];
        Q[0] = Q[size - 1];
        size--;
        minHeapify(Q, 0, size);
    }

    return min;
}

void minPQ_decrease(ll *Q, ll idx, ll key)
{
    if (key > Q[idx])
    {
        return;
    }
    else
    {
        Q[idx] = key;
        while (idx > 0)
        {
            swap(Q[idx], Q[(idx - 1) / 2]);
            idx = (idx - 1) / 2;
        }
    }
}

void minPQ_insert(ll *Q, ll key, ll &size)
{
    size++;
    Q[size - 1] = infinite;
    minPQ_decrease(Q, size - 1, key);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;

    while (cin >> n)
    {
        n--;

        bool impossible = true;

        ll PQ[n];

        for (int i = 0; i < n; i++)
        {
            cin >> PQ[i];
        }

        buildHeap(PQ, n);

        ll pqSize = n;

        ll prev = minPQ_extract(PQ, pqSize);

        ll missing = 0;

        while (pqSize > 0)
        {
            ll current = minPQ_extract(PQ, pqSize);

            if (current - prev == 1){
                prev = current;
                continue;
            }

            impossible = false;
            missing = current - 1;
            break;
        }

        if (impossible)
            cout << "IMPOSSIBLE";
        else    
            cout << missing;

        cout << endl;
    }
    return 0;
}