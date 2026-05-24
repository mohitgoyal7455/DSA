class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0;
        int j=nums.size()-1;
        for(int i=0;i<j+1;i++){

        
        while(i<j){
            if(nums[i]+nums[j]<target){
                i++;
            }
            else if(nums[i]+nums[j]==target){
                        return {i+1,j+1};
 
            }
            else{
                j--;
            }

        }
                
        }

        return {-1,-1};
        
    }
};