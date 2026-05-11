class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        string s;
        vector<int>ans;
        for(auto it:nums){
            s=to_string(it);
           for(auto i:s){
            ans.push_back(i-'0');
           }
        }
        return ans;
        
    }
};