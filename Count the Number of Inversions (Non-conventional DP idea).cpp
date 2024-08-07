class Solution {
public:
    int M = 1e9 + 7;

    int DP[305][405];

    int func(int idx, int inv, vector<int>& val, int n) {

        if (inv > 400) {
            return 0;
        }

        if (idx == n) {
            return 1;
        }

        if (DP[idx][inv] != -1) {
            return DP[idx][inv];
        }

        int ans = 0;

      //  Only the relative order of the elements matter here.
      
        for (int i = 0; i <= idx; i++) {
            if (val[idx] != -1) {
                if (val[idx] == (inv + i)) {
                    ans = (ans % M + func(idx + 1, inv + i, val, n) % M) % M;
                }
            } else {
                ans = (ans % M + func(idx + 1, inv + i, val, n) % M) % M;
            }
        }

        return DP[idx][inv] = ans % M;
    }

    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        vector<int> val(n, -1);

        for (auto& e : requirements) {
            val[e[0]] = e[1];
        }

        memset(DP, -1, sizeof(DP));

        return func(0, 0, val, n);
    }
};
