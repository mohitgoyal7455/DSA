class Solution {
public:
    long long sumAndMultiply(int n) {
        string s=to_string(n);
        long long sum=0,str=0;
        for(auto it:s){
            if(it!='0'){
                str=str*10+it-'0';
                sum+=it-'0';
            }
        }
            
        
        return sum*str;

        
    }
};