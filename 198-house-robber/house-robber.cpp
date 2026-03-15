class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>t(n+1,0);
       if(n<1){
        return 0;
       }
        t[0]=0;
        t[1]=nums[0];

        for(int i=2;i<=n;i++){
            int skip=t[i-1];
            int steal=nums[i-1]+t[i-2];
            
            t[i]=max(skip,steal);
        }
        return t[n];
        
    }
};