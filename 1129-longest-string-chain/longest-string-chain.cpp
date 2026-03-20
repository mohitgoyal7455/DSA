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
        int t[1001][1001];
    int lis(vector<string>&words,int prev_idx,int curr_idx){
        int n=words.size();
        if(curr_idx==n){
            return 0;
        }
        if(prev_idx!=-1 && t[prev_idx][curr_idx]!=-1 ){
            return t[prev_idx][curr_idx];

        }
        int taken=0,skip;
        if(prev_idx==-1 || ispred(words[prev_idx],words[curr_idx])){
            taken=1+lis(words,curr_idx,curr_idx+1);
        }
        skip=lis(words,prev_idx,curr_idx+1);
          if(prev_idx!=-1)
            t[prev_idx][curr_idx]=max(skip,taken);
          
       return max(skip,taken);

    } 
 int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),myfunction);
        memset(t,-1,sizeof(t));
        return lis(words,-1,0);
        
    }
};