void DFS(int node, int parent, vector<vector<int>> &Tree, vector<int> &Depth)
{
    Depth[node] = Depth[parent] + 1;

    for (auto &child : Tree[node])
    {
        if (child != parent)
        {
            DFS(child, node, Tree, Depth);
        }
    }

    return;
}

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> Tree(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int fst, snd;
        cin >> fst >> snd;

        Tree[fst].push_back(snd);
        Tree[snd].push_back(fst);
    }

    vector<int> Depth(n + 1);

    Depth[0] = -1;

    DFS(1, 0, Tree, Depth);

    int maxDepth = 0, node = 1;

    for (int i = 1; i <= n; i++)
    {
        if (Depth[i] > maxDepth)
        {
            maxDepth = Depth[i];
            node = i;
        }
        Depth[i] = 0;
    }

    DFS(node, 0, Tree, Depth);

    int diameter = 0;

    for (int i = 1; i <= n; i++)
    {
        if (Depth[i] > diameter)
        {
            diameter = Depth[i];
            node = i;
        }
        Depth[i] = 0;
    }

    cout << diameter << endl;

    return;
}
