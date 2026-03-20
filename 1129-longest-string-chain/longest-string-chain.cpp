class Solution {
public:
    bool static myfunction(string &s1,string&s2){
        return s1.length() < s2.length();
    }
    bool ispred(string &s1,string &s2){
        int N=s1.length();
        int M=s2.length();
        if(N>M || M-N!=1){
            return false;
        }
        int i=0,j=0;
        while(i<N && j<M){
            if(s1[i]==s2[j])
                i++;

            j++;   
            }

        return i==N;

        
    }
 int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),myfunction);
        vector<int>t(n,1);
        int maxl=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(ispred(words[j],words[i])){
                    t[i]=max(t[i],t[j]+1);
                    maxl=max(t[i],maxl);
                }
            }
        }
        return maxl;
        
    }
};