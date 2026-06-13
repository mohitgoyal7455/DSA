class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        
        string result;

        for(auto &it:words){
            int sum=0;
            for(auto &l : it){
                sum+=weights[l-'a'];
            }
            int val=sum%26;
            result.push_back(char('z' - val));

        }
        return result;
    }
};