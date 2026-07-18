class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int maxlen = 0;
        unordered_set<int> arr(nums.begin(), nums.end());
        for (int value : nums) {
            int cnt = 0, curr = value;
            while (arr.find(curr) != arr.end()) {
                cnt++, curr++;
            }
            maxlen = max(maxlen, cnt);
        }
        return maxlen;
    }
};
