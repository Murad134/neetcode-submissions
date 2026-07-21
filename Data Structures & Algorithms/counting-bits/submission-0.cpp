class Solution {
   public:
    vector<int> countBits(int n) {
        vector<int>vb;
        for (int i = 0; i <= n; i++) {
            int cnt = __builtin_popcount(i);
            vb.push_back(cnt);
        }
        return vb;
    }
};
