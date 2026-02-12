class Solution {
public:
    bool check(int freq[]){
        int i = 0;
        int j = 0;
        while(i<26 && j<26){
            if(freq[i]==0){
                i++;
                continue;
            }

            if(freq[j]==0){
                j++;
                continue;
            }

            if(freq[i]==freq[j]){
                i++;
            }else{
                return false;
            }
        }

        return true;
    }
    int longestBalanced(string s) {
        
        int maxLen = INT_MIN;

        for(int i=0;i<s.length();i++){
            int freq[26]={0};
            for(int j=i;j<s.length();j++){
                
                freq[s[j]-'a']++;
                if(check(freq)){
                    maxLen = max(maxLen,j-i+1);
                }
            }
        }

        return maxLen;
        
    }
};