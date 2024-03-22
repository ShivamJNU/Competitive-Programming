// Some commonly used functions in arithmetic number theory:
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
ll expo(ll a, ll b, ll mod) {a %= mod; ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll inv(ll a, ll b) {return expo(a, b - 2, b);}
ll nCr(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}

// Modular Arithmetic:
ll add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mul(a, inv(b, m), m) + m) % m;}  //only for prime m
