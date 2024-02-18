#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

// We can use greater<int> in the place of less<int> to store the elements in decreasing order
// We can even use less_equal<int> or greater_equal<int> in the place of less<int> to store elements like a multiset.
// (The functionality of order of key also changes in these cases.)

#define ll long long
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second

#define MOD 1000000007

#define REP(j, a, b) for (int j = a; j < b; j++)
#define print(x) cout << x << endl
#define yep cout << "YES" << endl
#define nope cout << "NO" << endl

#define int long long
#define sorted(x) sort(x.begin(), x.end())

void solve()
{

    ordered_set s1;

    // All operations have a T.C. of O(logN) in an ordered_set.

    s1.insert(1);
    s1.insert(5);
    s1.insert(0);
    s1.insert(8);
    s1.insert(15);
    s1.insert(10);
    s1.insert(12);
    s1.insert(51);
    s1.insert(0);

    for (auto &e : s1)
    {
        cout << e << " ";
    }
    cout << endl;

    // order_of_key returns the number of elements smaller than the given number.
    cout << s1.order_of_key(10) << endl;

    // find_by_order returns the iterator to the element present at the ith index where indexing starts from 0.
    cout << *(s1.find_by_order(5)) << endl;

    // lower_bound returns the iterator to the element greater than or equal to the given element.
    cout << *(s1.lower_bound(5)) << endl;

    // upper_bound returns the iterator to the element strictly greater than the given element.
    cout << *(s1.upper_bound(5)) << endl;
    return;
}

signed main()
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
