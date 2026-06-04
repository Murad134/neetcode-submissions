class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        for(int i:nums)
        {
            mp[i]++;
            if(mp[i]>1)
            {
                return true;
            }
        }
        return false;
    }
};