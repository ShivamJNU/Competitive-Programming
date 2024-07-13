#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define ff first
#define ss second
#define pb push_back
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define endl '\n'
#define mp make_pair
#define mii map<ll, ll>
#define pii pair<ll, ll>
#define vi vector<ll>
#define vvi vector<vi>
#define vb vector<bool>
#define vpii vector<pii>
#define ll long long
#define endl '\n'
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}
#define all(x) (x).begin(),(x).end()
const ll mod = 998244353;
#define fore(i, l, r) for(ll i = ll(l); i < ll(r); i++)
bool cmps(pii &a, pii &b)
{
    return a.ss < b.ss;
}
ll min(ll a,ll b)
{
    return a<b?a:b;
} 

struct testcase{
    ll n,l,r;
    vi arr;
};
ll randomNumber(ll a,ll b){
    return a + (rand() % b);
}
// Function to generate a random number between l and r
int ran(int l, int r) {
    return l + (rand() % (r - l + 1));
}


testcase generateTestCase(){
    testcase randomTest;
    ll n = randomNumber(1,9);
    ll l = randomNumber(1,10);
    ll r = randomNumber(l+1,12);
    randomTest.n = n;
    randomTest.l = l;
    randomTest.r = r;
    vi arr;
    REP(i,0,n)
    {
        ll ele = randomNumber(1,10);
        randomTest.arr.pb(ele);
    }
    return randomTest;
}
ll dfs_down(vvi& adj,vi& down,ll parent,ll node)
{
    if(adj[node].size() == 1 && adj[node][0] == parent)
    {
        down[node] = 1;
        return 1;
    }
    vi count = {0,0};
    for(auto x : adj[node])
    {
        if(x != parent)
        {
            ll curr = dfs_down(adj,down,node,x);
            count[curr]++;
        }
    }
    if(count[1] != 0)// if zero = 0;
    {
        down[node] = 0;
        return 0;
    }
    else
    {
        down[node] = 1;
        return 1;
    }
}
ll optimizedSolution(testcase T)
{
}
ll bruteForce(testcase T){


}
bool debugger(){
    testcase random = generateTestCase();
    ll ans1 = bruteForce(random);
    ll ans2= optimizedSolution(random);
    cout<<random.n<<endl;
    cout<<random.l<<endl;
    cout<<random.r<<endl;
    for(int i=0;i<random.n;i++)
    {
        cout<<random.arr[i]<<" ";
    }

    cout<<"Correct ANS : "<<endl;
    cout<<ans1<<endl;
    cout<<"Wrong ANS: "<<endl;
    cout<<ans2<<endl;
        cout<<endl<<endl<<endl<<endl;
        cout.flush();

    if(ans1 != ans2)
    return true;

    return false;
}


void solve()
{
    while(1)
    {
        if(debugger())
        break;
    }
}
int32_t main()
{
    solve();
    return 0;
}