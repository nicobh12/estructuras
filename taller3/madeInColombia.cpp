#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double

const ll infinite = 2e9;

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

void buildMinHeap(ll *Q, ll size)
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
        while (idx > 0 && Q[idx] < Q[(idx - 1) / 2])
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

void maxHeapify(ll *Q, ll i, ll size)
{
    ll l, r, min = i;

    l = 2 * i + 1;
    r = 2 * i + 2;

    if (l < size && Q[l] > Q[min])
    {
        min = l;
    }

    if (r < size && Q[r] > Q[min])
    {
        min = r;
    }

    if (min != i)
    {
        swap(Q[i], Q[min]);

        maxHeapify(Q, min, size);
    }
}

void buildMaxHeap(ll *Q, ll size)
{
    ll lastParentLeaf = (size / 2) - 1;

    for (ll i = lastParentLeaf; i >= 0; i--)
    {
        maxHeapify(Q, i, size);
    }
}

ll maxPQ_maximum(ll *Q, ll size)
{
    return Q[0];
}

ll maxPQ_extract(ll *Q, ll &size)
{
    ll min = infinite;
    if (size < 1)
    {
        exit(1);
    }
    else
    {
        min = Q[0];
        Q[0] = Q[size - 1];
        size--;
        maxHeapify(Q, 0, size);
    }

    return min;
}

void maxPQ_increase(ll *Q, ll idx, ll key)
{
    if (key < Q[idx])
    {
        return;
    }
    else
    {
        Q[idx] = key;
        while (idx > 0 && Q[idx] > Q[(idx - 1) / 2])
        {
            swap(Q[idx], Q[(idx - 1) / 2]);
            idx = (idx - 1) / 2;
        }
    }
}

void maxPQ_insert(ll *Q, ll key, ll &size)
{
    size++;
    Q[size - 1] = -infinite;
    maxPQ_increase(Q, size - 1, key);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    while (cin >> n && n != 0)
    {
        ll left[n / 2 + 1], right[n / 2 + 1];
        ll leftSize = 0, rightSize = 0;
        ll data, medianSum = 0;
        ld medianMedia = 0;

        cin >> data;

        maxPQ_insert(left, data, leftSize);

        medianSum += data;

        for (int i = 1; i < n; i++)
        {
            cin >> data;

            if (data <= maxPQ_maximum(left, leftSize))
                maxPQ_insert(left, data, leftSize);
            else
                minPQ_insert(right, data, rightSize);

            if (leftSize - rightSize > 1 || rightSize > leftSize)
            {
                if (leftSize > rightSize)
                {
                    int x = maxPQ_extract(left, leftSize);
                    minPQ_insert(right, x, rightSize);
                }
                else
                {
                    int x = minPQ_extract(right, rightSize);
                    maxPQ_insert(left, x, leftSize);
                }
            }

            medianSum += maxPQ_maximum(left, leftSize);
        }

        medianMedia = (ld)medianSum / (ld)n;

        cout << fixed << setprecision(2) << medianMedia << endl;
    }

    return 0;
}