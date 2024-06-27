class Solution
{
public:
    vector<int> minimumTime(int n, vector<vector<int>> &edges, vector<int> &disappear)
    {

        vector<vector<pair<int, int>>> Graph(n);

        for (auto &e : edges)
        {
            int src = e[0];
            int dst = e[1];
            int tm = e[2];

            Graph[src].push_back({dst, tm});
            Graph[dst].push_back({src, tm});
        }

        vector<int> vis(n, 0);
        vector<int> distance(n, 1e9 + 10);

        distance[0] = 0;

        set<pair<int, int>> s1;

        s1.insert({0, 0});

        while (s1.size() != 0)
        {
            auto it = s1.begin();
            auto p1 = *it;

            // p1.first-> distance from source and p1.second-> the node

            if (distance[p1.second] < p1.first)
            {
                vis[p1.second] = 1;
                s1.erase(it);
                continue;
            }

            for (auto &child : Graph[p1.second])
            {
                if (!vis[child.first])
                {
                    distance[child.first] = min(distance[child.first], p1.first + child.second);

                    if (distance[child.first] < disappear[child.first])
                    {
                        s1.insert({distance[child.first], child.first});
                    }
                    else
                    {
                        distance[child.first] = 1e9 + 10;
                    }

                    // vis[child.first]=1;
                }
            }

            vis[p1.second] = 1;
            s1.erase(it);
        }

        for (auto &e : distance)
        {
            if (e > 1e9)
            {
                e = -1;
            }
        }

        return distance;
    }
};
