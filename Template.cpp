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
#define yep cout << "YES" << endl
#define nope cout << "NO" << endl

#define int long long
#define sorted(x) sort(x.begin(), x.end())

void solve()
{
    int n;
    cin>>n;

    vector<long long>vec1(n);

    for(int i=0;i<n;i++){
        cin>>vec1[i];
    }

    return;
}

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}

/* --> There is an inbuilt GCD function in STL: __gcd(a, b)
   --> LCM (a, b) = (a*b)/GCD (a, b)
  
   --> To check the ith bit in a number: (N>>i) & 1 
  (Here the index starts from 0 and goes till 30 i.e. total 31 bits can be checked as the MSB is for sign)
  
   --> To calculate the powers of 2 use LSO: (1<<i)
   --> To check if a number is a power of 2: N & (N-1) == 0
  
   --> To check the ith bit in a number: (N>>i) & 1 


*/

/*
   --> THE FORMAT OF BINARY SEARCH ON ANSWER:
   
   int left, right;

    while (right - left > 1)
    {
        int mid = (right + left) / 2;

        if (check(mid))
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }

*/
