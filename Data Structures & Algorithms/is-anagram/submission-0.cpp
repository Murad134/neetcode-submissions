class Solution {
   public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        int sz = s.length();
        int tz = t.length();
        if (sz != tz) return false;

        for (int i = 0; i < sz; i++) {
            if (s[i] != t[i]) {
                return false;
            }
        }
        return true;
    }
};
