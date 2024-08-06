#define M 1000000007
#define MOD 1000000007
#define N 200007

ll fact[N + 1];
ll inv[N + 1];
ll invFact[N + 1];

// Just call the compute function in the main function and then ncr function can simply be used anywhere.
void compute()
{

    inv[0] = inv[1] = 1;

    for (int i = 2; i <= N; i++)
    {
        inv[i] = (inv[MOD % i] * (MOD - MOD / i)) % MOD;
    }

    invFact[0] = invFact[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        invFact[i] = (invFact[i - 1] * inv[i]) % MOD;
    }

    fact[0] = fact[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

// While using ncr function just make sure that k<=n && k>=0, otherwise unusual behaviour would be encountered.
ll ncr(ll n, ll k)
{
    return (((fact[n] * invFact[k]) % MOD) * invFact[n - k]) % MOD;
}
