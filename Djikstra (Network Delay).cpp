class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {

        vector<vector<pair<int, int>>> Graph(n + 1);

        for (auto &e : times)
        {
            int src = e[0];
            int dst = e[1];
            int tm = e[2];

            Graph[src].push_back({dst, tm});
        }

        vector<int> vis(n + 1, 0);
        vector<int> distance(n + 1, 1e9 + 10);

        distance[k] = 0;

        set<pair<int, int>> s1;

        s1.insert({0, k});

        while (s1.size() != 0)
        {
            auto it = s1.begin();
            auto p1 = *it;

            // p1.first-> distance from source and p1.second-> the node

            for (auto &child : Graph[p1.second])
            {
                if (!vis[child.first])
                {
                    distance[child.first] = min(distance[child.first], p1.first + child.second);
                    s1.insert({distance[child.first], child.first});
                    // vis[child.first]
                }
            }

            vis[p1.second] = 1;
            s1.erase(it);
        }

        int maxa = -1;

        for (int i = 1; i <= n; i++)
        {

            if (distance[i] == (1e9 + 10))
            {
                return -1;
            }

            maxa = max(maxa, distance[i]);
        }

        return maxa;
    }
};

// Adding the below code snippet might make Djikstra Algo faster in some cases, (we avoid using it in case when visiting atleast k nodes before is compulsion):
/*
if (p1.first > distance[p1.second])
{
    vis[p1.second] = 1;
    s1.erase(it);
    continue;
}
*/

// Maintaining a boolean visited array is not mandatory, we can do it in the following way:

class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {

        vector<vector<pair<int, int>>> Graph(n);

        for (auto& e : edges) {
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

        while (s1.size() != 0) {
            auto it = s1.begin();
            auto p1 = *it;

            // p1.first-> distance from source and p1.second-> the node

            if (distance[p1.second] < p1.first) {
                // vis[p1.second] = 1;
                s1.erase(it);
                continue;
            }

            for (auto& child : Graph[p1.second]) {
                if ((p1.first + child.second < distance[child.first])) {
                    distance[child.first] = min(distance[child.first], p1.first + child.second);

                    if (distance[child.first] < disappear[child.first]) {
                        s1.insert({distance[child.first], child.first});
                    } else {
                        distance[child.first] = 1e9 + 10;
                    }

                    // vis[child.first]=1;
                }
            }

            // vis[p1.second] = 1;
            s1.erase(it);
        }

        for (auto& e : distance) {
            if (e > 1e9) {
                e = -1;
            }
        }

        return distance;
    }
};


