class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), mxlen = 0;
        vector<int> hash(256, -1);
        int l = 0, r = 0, len = 0;
        while (r < n) {
            if (hash[s[r]] != -1) {
                l = max(l, hash[s[r]] + 1);
            }
            len = r - l + 1;
            mxlen = max(mxlen, len);
            hash[s[r]] = r;
            r++;
        }
        return mxlen;
    }
};
