
class Solution {
public:
    int t[1001][1001];
    int LCS(string& s1, string& s2, int m, int n) {
        if(m>=s1.length() || n>=s2.length())
            return t[m][n] = 0;
        
        if(t[m][n] != -1)
            return t[m][n];
        
        if(s1[m] == s2[n])
            return t[m][n] = 1 + LCS(s1, s2, m+1, n+1);
        
        return t[m][n] = max(LCS(s1, s2, m, n+1), LCS(s1, s2, m+1, n));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        memset(t, -1, sizeof(t));
        
        return LCS(text1, text2, 0, 0);
    }
};