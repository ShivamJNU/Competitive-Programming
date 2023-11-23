#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define endl "\n"

#define pb push_back

#define ppb pop_back

#define ff first

#define ss second

#define MOD 1000000007




int lowest(vector<int> &vec1, int index, vector<int> &DP){
    if(index==0){
        return DP[0];
    }

    if(index==1){
        return DP[1];
    }

    if(DP[index-1]==-1){
        DP[index-1]=lowest(vec1, index-1, DP);
    }

    if(DP[index-2]==-1){
        DP[index-2]=lowest(vec1, index-2, DP);
    }

    return min((DP[index-1]+abs(vec1[index]-vec1[index-1])),(DP[index-2]+abs(vec1[index]-vec1[index-2])));
}

void solve()
{

    int n;

    cin >> n;

    vector<int> vec1(n);
    vector<int>DP(n,-1);
    DP[0]=0;
    

    for (int i = 0; i < n; i++)
    {
        cin >> vec1[i];
    }

    DP[1]=abs(vec1[1]-vec1[0]);

    cout<<lowest(vec1, n-1, DP)<<endl;

        return;
}

int main()
{

    int t=1;

    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
