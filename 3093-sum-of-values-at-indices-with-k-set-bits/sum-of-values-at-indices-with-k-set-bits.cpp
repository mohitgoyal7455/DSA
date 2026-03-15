class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans = 0;
        int bitcount;

        for(int i = 0; i < nums.size(); i++){
            bitcount = __builtin_popcount(i);
            if(bitcount == k){
                ans += nums[i];
            }
        }

        return ans;
    }
};