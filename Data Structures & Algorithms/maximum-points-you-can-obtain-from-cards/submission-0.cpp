class Solution {
   public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> pre(n + 1, 0), suff(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + cardPoints[i];
        }

        for (int i = n-1; i>=0 ; i--) {
            suff[i] = suff[i+1] + cardPoints[i];
        }
        int ans =0;
        for (int left = 0; left <= k; left++) {
            int right = k-left;
            ans =max(ans, suff[n-right]+pre[left]);
        }
        return ans;
    }
};