// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update

// using namespace std;
// using namespace __gnu_pbds;

// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

// // We can use greater<int> in the place of less<int> to store the elements in decreasing order
// // We can even use less_equal<int> or greater_equal<int> in the place of less<int> to store elements like a multiset.
// // (The functionality of order of key also changes in these cases.)

// #define ll long long
// #define endl "\n"
// #define pb push_back
// #define ppb pop_back
// #define ff first
// #define ss second

// #define MOD 1000000007

// #define REP(j, a, b) for (int j = a; j < b; j++)
// #define print(x) cout << x << endl
// #define yep cout << "YES" << endl
// #define nope cout << "NO" << endl

// #define int long long
// #define sorted(x) sort(x.begin(), x.end())

// void solve()
// {

//     int n, x, y;
//     cin >> n >> x >> y;

//     vector<int> vec1(n);

//     REP(i, 0, n)
//     {
//         cin >> vec1[i];
//     }

//     map<pair<int, int>, int> m1;

//     for (auto &e : vec1)
//     {
//         int fst = e % x;
//         int snd = e % y;

//         pair<int, int> p1 = make_pair(fst, snd);

//         m1[p1]++;
//     }

//     int total = 0;

//     for (auto &e : vec1)
//     {
//         int fst = e % x;
//         int snd = e % y;

//         pair<int, int> p1 = make_pair(fst, snd);
//         pair<int, int> p2 = make_pair((x - fst) % x, snd);

//         if (p1 == p2)
//         {
//             int cnt = m1[p1];

//             cnt = cnt * (cnt - 1);
//             cnt = cnt / 2;

//             total += cnt;

//             m1.erase(p1);
//         }
//         else
//         {
//             if (m1.find(p2) != m1.end())
//             {
//                 int cnt = m1[p1] * m1[p2];

//                 total += cnt;
//             }

//             auto itr = m1.find(p1);

//             if (itr != m1.end())
//             {
//                 m1.erase(itr);
//             }
//         }
//     }

//     print(total);

//     return;
// }

// signed main()
// {

//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     int t = 1;
//     cin >> t;

//     while (t--)
//     {
//         solve();
//     }
//     return 0;
// }

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
