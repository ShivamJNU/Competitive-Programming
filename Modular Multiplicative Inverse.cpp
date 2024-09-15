#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int bin_exp(int a, int b) {
    if (b == 0) {
        return 1;
    }
    if (b % 2) {
        return bin_exp(a, b - 1) * 1LL * a % mod;
    }
    int res = bin_exp(a, b / 2);
    return res * 1LL * res % mod;
}

int inv(int a) {
    return bin_exp(a, mod - 2);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int a, b;
    cin >> a >> b;
    cout << a * 1LL * inv(b) % mod << '\n';
    cout<<"hi"<<endl;
}
