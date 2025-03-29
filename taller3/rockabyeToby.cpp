#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define infinite 2e9

struct tiempoPrioridad{
    int time;
    int priority;
};

struct periodoNombre{
    int period;
    string name;
};

struct rockabyeToby{
    struct tiempoPrioridad t;
    struct periodoNombre medicine; 
};

void minHeapify(struct rockabyeToby *Q, int i, int size)
{
    int l, r, min = i;

    l = 2 * i + 1;
    r = 2 * i + 2;

    if (l < size && (Q[l].t.time < Q[min].t.time || (Q[l].t.time == Q[min].t.time && Q[l].t.priority < Q[min].t.priority)))
    {
        min = l;
    }

    if (r < size && (Q[r].t.time < Q[min].t.time || (Q[r].t.time == Q[min].t.time && Q[r].t.priority < Q[min].t.priority)))
    {
        min = r;
    }

    if (min != i)
    {
        swap(Q[i], Q[min]);

        minHeapify(Q, min, size);
    }
}

void buildHeap(struct rockabyeToby *Q, int size)
{
    int lastParentLeaf = (size / 2) - 1;

    for (int i = lastParentLeaf; i >= 0; i--){
        minHeapify(Q, i, size);
    }
}

struct rockabyeToby minPQ_minimum(struct rockabyeToby *Q, int size){
    return Q[0];
}

struct rockabyeToby minPQ_extract(struct rockabyeToby *Q, int &size){
    struct rockabyeToby min;
    min.t.time = -infinite;

    if (size < 1){
        exit(1);
    }
    else{
        min = Q[0];
        Q[0] = Q[size - 1];
        size--;
        minHeapify(Q, 0, size);
    }

    return min;
}

void minPQ_decrease(struct rockabyeToby *Q, int idx, struct rockabyeToby key){
    if (key.t.time > Q[idx].t.time){
        return;
    }
    else{
        Q[idx] = key;
        int parent = (idx - 1)/2;
        while (idx > 0 && (Q[idx].t.time < Q[parent].t.time || (Q[idx].t.time == Q[parent].t.time && Q[idx].t.priority < Q[parent].t.priority))){
            swap(Q[idx], Q[parent]);
            idx = parent;
            parent = (idx - 1)/2;
        }
    }
}

void minPQ_insert(struct rockabyeToby *Q, struct rockabyeToby key, int &size){
    size++;
    Q[size - 1].t.time = infinite;
    minPQ_decrease(Q, size - 1, key);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        struct rockabyeToby PQ[n];

        for (int i = 0; i < n; i++)
        {
            string medicine;
            int time;
            cin >> medicine >> time;

            PQ[i].t.time = time;
            PQ[i].t.priority = i;
            PQ[i].medicine.name = medicine;
            PQ[i].medicine.period = time;
        }

        buildHeap(PQ, n);

        while(k--){
            
            struct rockabyeToby p = minPQ_extract(PQ, n);

            cout << p.t.time << " " << p.medicine.name << endl;

            p.t.time += p.medicine.period; 
            
            minPQ_insert(PQ, p, n);
        }
    }

    return 0;
}