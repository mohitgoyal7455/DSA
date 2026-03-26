class Solution {
public:
    int t[1001][1001];
    bool check(string &s,int i,int j){
        int n=s.length();

        if(i>j){
            return true;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        if(s[i]==s[j]){
            return t[i][j]=check(s,i+1,j-1);
        }
        
            return t[i][j]=false;
        
    }
    string longestPalindrome(string s) {
        int n=s.length();
        int maxlen=INT_MIN;
        int sp=0;
        memset(t,-1,sizeof(t));
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(check(s,i,j)){
                        if(j-i+1>maxlen){
                            maxlen=j-i+1;
                            sp=i;
                        }
                        

                    }
                }
            }
            return s.substr(sp,maxlen);        
    }
};