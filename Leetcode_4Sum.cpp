class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        map<long long, long long> m1;

        for (auto &e : nums)
        {
            m1[e]++;
        }

        int x;

        for (int i = 0; i < n;)
        {
            m1[nums[i]]--;

            for (int j = i + 1; j < n;)
            {
                m1[nums[j]]--;
                for (int k = j + 1; k < n;)
                {
                    m1[nums[k]]--;
                    long long req = (long long)target - (long long)nums[i] - (long long)nums[j] - (long long)nums[k];

                    if (m1[req] > 0)
                    {
                        ans.push_back({nums[i], nums[j], nums[k], (int)req});
                    }

                    x = k;
                    bool con = false;

                    while (k < n && nums[k] == nums[x])
                    {
                        if (con)
                        {
                            m1[nums[k]]--;
                        }
                        con = 1;
                        k++;
                    }
                }

                for (int k = j + 1; k < n; k++)
                {
                    m1[nums[k]]++;
                }

                x = j;
                bool con = false;

                while (j < n && nums[j] == nums[x])
                {
                    if (con)
                    {
                        m1[nums[j]]--;
                    }
                    con = 1;
                    j++;
                }
            }

            for (int j = i + 1; j < n; j++)
            {
                m1[nums[j]]++;
            }

            x = i;
            bool con = false;

            while (i < n && nums[i] == nums[x])
            {
                if (con)
                {
                    m1[nums[i]]--;
                }
                con = 1;
                i++;
            }
        }

        return ans;
    }
};
