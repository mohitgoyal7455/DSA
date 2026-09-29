class Solution {
public:
    bool isPalindrome(string s) {
        string str;

        for(auto it :s){
            if(isalnum(it)){
                str.push_back(tolower(it));
            }
            else{
                continue;
            }
        }
        

        int i=0,j=str.size()-1;
        while(i<j){
            if(str[i]==str[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};