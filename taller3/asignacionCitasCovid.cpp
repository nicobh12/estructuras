#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pis pair<ll, string>
#define infinite 2e9

const  ll maxn = 1e6;
const ll maxt = 1e7;

struct paciente{
    ll priority;
    string name;
};

void maxHeapify(struct paciente *Q, int i, int size)
{
    int l, r, max = i;

    l = 2 * i + 1;
    r = 2 * i + 2;

    if (l < size && Q[l].priority > Q[max].priority)
    {
        max = l;
    }

    if (r < size && Q[r].priority > Q[max].priority)
    {
        max = r;
    }

    if (max != i)
    {
        swap(Q[i], Q[max]);

        maxHeapify(Q, max, size);
    }
}

void buildHeap(struct paciente *Q, int size)
{
    int lastParentLeaf = (size / 2) - 1;

    for (int i = lastParentLeaf; i >= 0; i--){
        maxHeapify(Q, i, size);
    }
}

struct paciente maxPQ_maximum(struct paciente *Q, int size){
    return Q[0];
}

struct paciente maxPQ_extract(struct paciente *Q, int &size){
    struct paciente max;
    max.priority = infinite;

    if (size < 1){
        exit(1);
    }
    else{
        max = Q[0];
        Q[0] = Q[size - 1];
        size--;
        maxHeapify(Q, 0, size);
    }

    return max;
}

void maxPQ_increase(struct paciente *Q, int idx, struct paciente key){
    if (key.priority < Q[idx].priority){
        return;
    }
    else{
        Q[idx] = key;
        while (idx > 0 && Q[idx].priority > Q[(idx - 1)/2].priority){
            swap(Q[idx], Q[(idx - 1)/2]);
            idx = (idx - 1)/2;
        }
    }
}

void maxPQ_insert(struct paciente *Q, struct paciente key, int &size){
    size++;
    Q[size - 1].priority = -infinite;
    maxPQ_increase(Q, size - 1, key);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string n;
    
    struct paciente *PQ= new struct paciente[maxn];
    ;

    ll i = 0;
    int pqSize = 0;

    while(cin >> n){
        if (n == "V"){
            if (pqSize > 0){
                struct paciente attention = maxPQ_extract(PQ, pqSize);

                cout << attention.name;
            }

            cout << endl;
        }
        else{
            ll p;
            cin >> p;
            p = p*maxn - i;

            struct paciente toInsert;
            toInsert.name = n;
            toInsert.priority = p;

            maxPQ_insert(PQ, toInsert, pqSize);
            i++;
        }
    }
    
    return 0;
}