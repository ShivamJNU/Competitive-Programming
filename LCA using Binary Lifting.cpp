void DFS(int node, int pr, vector<vector<int>> &Tree, vector<vector<int>> &parent, vector<int> &depth)
{
    parent[node][0] = pr;
    depth[node] = depth[pr] + 1;

    for (int i = 1; i < 20; i++)
    {
        parent[node][i] = parent[parent[node][i - 1]][i - 1];
    }

    for (auto &child : Tree[node])
    {
        if (child != pr)
        {
            DFS(child, node, Tree, parent, depth);
        }
    }
}

void solve(int t)
{
    int n, q;
    cin >> n >> q;

    vector<vector<int>> Tree(n + 5);
    vector<int> depth(n + 5, -1);

    for (int i = 0; i < n - 1; i++)
    {
        int fst, snd;
        cin >> fst;

        snd = i + 2;

        Tree[fst].pb(snd);
        Tree[snd].pb(fst);
    }

    vector<vector<int>> parent(n + 5, vector<int>(20, 0));

    DFS(1, 0, Tree, parent, depth);

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;

        if (depth[a] < depth[b])
        {
            swap(a, b);
        }

        int df = depth[a] - depth[b];

        for (int i = 19; i >= 0; i--)
        {
            if ((df >> i) & 1)
            {
                a = parent[a][i];
            }
        }

        // cout << a << " " << b << endl;

        if (a == b)
        {
            cout << a << endl;
            continue;
        }

        for (int i = 19; i >= 0; i--)
        {
            if (parent[a][i] != parent[b][i])
            {
                a = parent[a][i];
                b = parent[b][i];
            }
        }

        // cout << a << " " << b << endl;

        cout << parent[a][0] << endl;
    }

    return;
}
