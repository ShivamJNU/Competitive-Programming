void DFS(int node, int pr, vector<vector<int>> &Tree, vector<vector<int>> &parent)
{
    parent[node][0] = pr;

    for (int i = 1; i < 20; i++)
    {
        parent[node][i] = parent[parent[node][i - 1]][i - 1];
    }

    for (auto &child : Tree[node])
    {
        if (child != pr)
        {
            DFS(child, node, Tree, parent);
        }
    }
}

void solve(int t)
{
    int n, q;
    cin >> n >> q;

    vector<vector<int>> Tree(n + 5);

    for (int i = 0; i < n - 1; i++)
    {
        int fst, snd;
        cin >> fst;

        snd = i + 2;

        Tree[fst].pb(snd);
        Tree[snd].pb(fst);
    }

    vector<vector<int>> parent(n + 5, vector<int>(20, 0));

    DFS(1, 0, Tree, parent);

    for (int i = 0; i < q; i++)
    {
        int x, k;
        cin >> x >> k;

        int p = 0;

        while (k != 0)
        {
            if (k & 1)
            {
                x = parent[x][p];
            }
            k = k >> 1;
            p++;
        }
        if (x == 0)
        {
            x = -1;
        }
        cout << x << endl;
    }

    return;
}
