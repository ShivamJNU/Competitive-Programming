// Code Snippet to generate random integer between 0 and i:

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(i) uniform_int_distribution<int>(0, i)(rng)

// if you want 64-bit random numbers, just use mt19937_64 instead.
