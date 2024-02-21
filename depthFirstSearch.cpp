#include <bits/stdc++.h>

using namespace std;

const int N = 10e5;

bool vis[N] = {0}; // initialize all the the visited array value as 0 which means false

vector<int> graph[N];

void makelink(int s, int d)
{

    graph[s].push_back(d);

    graph[d].push_back(s);
}

void dfs(int v)
{

    cout << v << endl;

    vis[v] = true;

    for (int child : graph[v])
    {

        cout << "par " << v << " child " << child << endl;

        if (vis[child])
            continue;

        dfs(child);
    }
}

int main()

{

    int v, e;

    cin >> v >> e;

    while (e--)
    {

        int s, d;

        cin >> s >> d;

        makelink(s, d);
    }

    cout << endl;

    dfs(v);

    return 0;
}
