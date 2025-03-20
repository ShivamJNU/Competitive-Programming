// Parent of all the nodes belonging to the same graph component becomes the same after we run a fianl find(i) loop for all the nodes in the graph.
// Refer this problem: https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph

#include <bits/stdc++.h>
using namespace std;

// Time Complexity of DSU: Amortized time complexity: Value increases very slowly

const int N = 1e5 + 10;

int parent[N];
int size[N];

void make(int v)
{
    parent[v] = v;
    size[v] = 1;
}

int find(int v)
{
    if (parent[v] == v)
    {
        return v;
    }

    // Path Compression
    return parent[v] = find(parent[v]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
    {
        // Tree of a should have greater size than Tree of b for optimisation
        if (size[a] < size[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
        return;
    }
}

void solve(int t, int NN)
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;

        Union(u, v);
    }

    int connectedComponentsCount = 0;

    for (int i = 1; i <= n; i++)
    {
        if (find(i) == i)
        {
            connectedComponentsCount++;
        }
    }

    cout << connectedComponentsCount << endl;

    return;
}
