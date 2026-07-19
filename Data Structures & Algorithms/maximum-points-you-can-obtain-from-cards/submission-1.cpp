class Solution {
   public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = 0, l = 0, r = n - k, mx = 0;
        for (int i = r; i < n; i++) {
            total += cardPoints[i];
        }
        mx = total;
        while (r < n) {
            total += (cardPoints[l] - cardPoints[r]);
            mx = max(total, mx);
             l++, r++;
        }
        return mx;
    }
};