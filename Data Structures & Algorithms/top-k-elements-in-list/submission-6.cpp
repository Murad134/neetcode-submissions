class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        for (auto it : nums) {
            ump[it]++;
        }
        vector<vector<int>>vec(nums.size() + 1);
        for (auto& it : ump){
            vec[it.second].push_back(it.first);
        }
        vector<int> ans;
        for (int i = nums.size(); i >= 1; i--) {
            for (int num : vec[i]) {
                ans.push_back(num);
                if (ans.size() == k) {
                    return ans;
                }
            }
        }
        return ans;
    }
};
