class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int components = target - nums[i];
            if (mp.find(components) != mp.end()) {
                return {mp[components], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
