class Solution {
public:
    string common(string s1,string s2){
        int n=min(s1.length(),s2.length());
        string str1="";
        for(int i=0;i<n;i++){
            if(s1[i]==s2[i]){
                str1.push_back(s1[i]);
            }
            else{
                break;
            }
        }
        return str1;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string res=strs[0];
        
        for(int i=1;i<n;i++){
            res=common(res,strs[i]);
        }
        return res;

    }
};