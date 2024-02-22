#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second

#define MOD 1000000007

#define REP(j, a, b) for (int j = a; j < b; j++)
#define print(x) cout << x << endl

void solve()
{

    long long n;
    cin >> n;

    vector<pair<int, long long>> val;
    for (long long i = 2; i * i <= n; ++i)
    {
        int cnt = 0;
        while (n % i == 0)
        {
            ++cnt;
            n /= i;
        }
        if (cnt > 0)
        {
            val.push_back({cnt, i});
        }
    }
    if (n > 1)
    {
        val.push_back({1, n});
    }

    sort(val.rbegin(), val.rend());

    return;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}