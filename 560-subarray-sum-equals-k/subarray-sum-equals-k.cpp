class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        mp.insert({0,1});
        int result=0;
        int prefixsum=0;
        for(int i=0;i<n;i++){
            prefixsum+=nums[i];
            if(mp.find(prefixsum-k)!=mp.end()){
                result+=mp[prefixsum-k];
            }
            mp[prefixsum]++;

        }
        return result;
        
    }
};