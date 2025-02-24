#include <bits/stdc++.h>
using namespace std;
#define MAXT 1000000

long long int arr[MAXT / 2];

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long int x, y, n, layer;
        cin >> x >> y;

        bool found = false;

        if (y <= 0)
        {
            unsigned long long int x_component = abs(y) + 1;

            long long int end = 2 * (-1 * x_component) + 1, start = 2 * x_component - 1;

            if (x >= end && x <= start)
            {
                long long int ref = (start - 1) * (start - 1) + 1;

                if (start == x){
                    n = (start + 1)*(start + 1);
                }
                else{
                    n = ref + abs(x - start + 1);
                }

                found = true;
            }
        }

        if (!found)
        {
            long long int diff = abs(0 - x);

            long long int layer = y + diff;

            long long int ref = (2 * layer) * (2 * layer - 1) + 1;

            if (x < 0)
            {
                n = ref - diff;
            }
            else
            {
                n = ref + diff;
            }
        }

        cout<<n<<endl;
    }
    return 0;
}