class Solution {
public:
    vector<int> countBits(int n) {
        // dp[i] stores the number of set bits in i
        vector<int> dp(n + 1);

        // Compute set bits for every number from 1 to n
        for (int i = 1; i <= n; i++) {

            // i >> 1 : Remove the last bit (i / 2)
            // dp[i >> 1] : Set bits of the remaining part
            // (i & 1) : Check if the last bit is 1 (adds 1) or 0 (adds 0)
            dp[i] = dp[i >> 1] + (i & 1);
        }

        // Return the set bit count for all numbers
        return dp;
    }
};