class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int left=0;
        unordered_map<char,int>mp;
        int maxlen=0;
        for(int right=0;right<n;right++){
            if(mp.find(s[right])!=mp.end()){
                left=max(left,mp[s[right]]+1);
            }
            mp[s[right]]=right;
            maxlen=max(maxlen,right-left+1);
        }
        return maxlen;
    }

};
