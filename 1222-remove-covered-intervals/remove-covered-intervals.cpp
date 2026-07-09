class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        auto lambda =[](vector<int> &v1 ,vector<int>&v2){

            if(v1[0]==v2[0]){
                return v1[1]>v2[1];
            }
            return v1[0]<v2[0];
            };

            sort(intervals.begin(),intervals.end(),lambda);

        vector<vector<int>>result;
        result.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(result.back()[0]<=intervals[i][0] && result.back()[1]>=intervals[i][1]  ){
                continue;
            }
            result.push_back(intervals[i]);
        }
        return result.size();
    }
};