// Solution for the Chat Screenshots Problem on Codeforces: https://codeforces.com/problemset/problem/1931/F
// Technique Used: Cycle finding in a directed graph using DFS with vis and pathvis array.

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define REP(j, a, b) for (int j = a; j < b; j++)
#define yep cout << "YES" << endl
#define nope cout << "NO" << endl

int ans = 1;
int tt = 0;

void DFS(int node, vector<vector<int>> &graph, vector<int> &vis, vector<int> &pathvis)
{
    vis[node] = 1;
    pathvis[node] = 1;

    for (auto &child : graph[node])
    {
        if (!vis[child])
        {
            DFS(child, graph, vis, pathvis);
        }
        else if (pathvis[child])
        {
            ans = 0;
        }
    }

    pathvis[node] = 0;
    return;
}

void solve(int t)
{
    tt++;
    ans = 1;

    int n, k;
    cin >> n >> k;

    vector<vector<int>> vec(k, vector<int>(n));

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> vec[i][j];
        }
    }

    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < k; i++)
    {
        for (int j = 1; j + 1 < n; j++)
        {
            graph[vec[i][j]].push_back(vec[i][j + 1]);
        }
    }

    vector<int> vis(n + 5, 0);
    vector<int> pathvis(n + 5, 0);

    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            DFS(i, graph, vis, pathvis);
        }
    }

    if (ans)
    {
        yep;
        return;
    }

    nope;
    return;
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve(t);
    }
    return 0;
}
