class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        int m=INT_MIN;
        vector<long long> arr(n);
        
        for(int i=0;i<n;i++){
            m=max(nums[i],m);
            arr[i]=gcd(m,nums[i]);
        }
        sort(arr.begin(),arr.end());
        long long ans=0;
        int i=0;
        int j=arr.size()-1;
        while(i<j){
        ans+=gcd(arr[i],arr[j]);
        i++;
        j--;
        }
        return ans;
        }

    
};