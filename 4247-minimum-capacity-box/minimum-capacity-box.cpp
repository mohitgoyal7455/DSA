class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int minimum1=INT_MAX;;
        for(int i=0;i<capacity.size();i++){
            if(capacity[i]>=itemSize){
                int size=capacity[i];
                minimum1=min(size,minimum1);
                continue;

            }
            
        }
       for(int i=0;i<capacity.size();i++){
        if(minimum1 ==capacity[i]){
            return i;
        }
       }
        return -1;
    }
};