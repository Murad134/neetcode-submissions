class Solution {
   public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (n) {
        // remove right most set bit
            n &= n - 1;
            cnt++;
        }
        return cnt;
    }
};
