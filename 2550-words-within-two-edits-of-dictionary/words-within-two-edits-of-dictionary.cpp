class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {

        int n=queries.size();
        int m=dictionary.size();
        vector<string>result;
        for(auto q:queries){
            for(auto d:dictionary){
                if(q.size()!=d.size())
                    continue; 
                int diff=0;
                for(int i=0;i<q.size();i++){
                    if(q[i] != d[i]){
                        diff++;
                    }  
                    if(diff>2)
                    break;
                }
                if (diff <= 2) {
                    result.push_back(q);
                     break;
                } 
            }
        }
        return result;
    }
};
