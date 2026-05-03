class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()){
            return false;
        }
        for(int count =1;count <=s.size();count++){
            rotate(s.begin(),s.begin()+1,s.end());
                if(s==goal){
                    return true;
                   
                }
        }
        return false;
        
    }
};