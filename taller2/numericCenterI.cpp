#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define maxn 1000001

ll gauss[maxn ];
int center[maxn];

int binarySearch(int start, int end, ll x, ll *A)
{
    int mid;
    while (start <= end)
    {
        mid = (start + end) >> 1;
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

void triangular()
{
    gauss[1] = 1;
    for (ll i = 2; i < maxn; i++)
    {
        gauss[i] = i + gauss[i - 1];
    }
}

void centers()
{
    int c = 0, j = 0, r;
    for (int i = 2; i < maxn; i++)
    {
        ll s = gauss[i] + gauss[i - 1];
        r = binarySearch(1, maxn - 1, s, gauss);

        if (r > 0)
        {
            j = r;
        }

        if (i == j)
        {
            c++;
        }

        center[i] = c;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;

    triangular();
    centers();

    while(cin >> n && n != 0){
        cout << center[n] << endl;
    }

    return 0;
}