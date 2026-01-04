class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int tar) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            int first=arr[i];
            int rem =tar-first;
            if(m.find(rem)!=m.end())
            {
                ans.push_back(i);
                ans.push_back(m[rem]);
                break;
            }
            m[first]=i;
        }
        return ans;


    }
};
