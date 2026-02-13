class Solution {
public:
    
    int solve(string &s, char c1, char c2, char skip){
        int maxLen = 0;
        int n = s.size();
        
        for(int i = 0; i < n; i++){
            
            while(i < n && s[i] == skip) i++;
            if(i >= n) break;
            
            int p = i;
            while(i < n && s[i] != skip) i++;
            int q = i - 1;
            
            int x = 0, y = 0;
            unordered_map<int,int> mp;
            mp[0] = p - 1;
            
            for(int j = p; j <= q; j++){
                if(s[j] == c1) x++;
                else if(s[j] == c2) y++;
                
                int key = x - y;
                
                if(mp.count(key)){
                    maxLen = max(maxLen, j - mp[key]);
                } else {
                    mp[key] = j;
                }
            }
        }
        return maxLen;
    }

    int longestBalanced(string s) {
        int n = s.size();
        
        int len = 1, mx = 1;
        
        // longest repeating char
        for(int i = 1; i < n; i++){
            if(s[i] == s[i-1]){
                len++;
                mx = max(mx, len);
            } else {
                len = 1;
            }
        }
        
        int a = 0, b = 0, c = 0;
        unordered_map<string,int> mp;
        mp["0,0"] = -1;
        
        for(int i = 0; i < n; i++){
            if(s[i] == 'a') a++;
            else if(s[i] == 'b') b++;
            else c++;
            
            int diff1 = a - b;
            int diff2 = a - c;
            
            string key = to_string(diff1) + "," + to_string(diff2);
            
            if(mp.count(key)){
                mx = max(mx, i - mp[key]);
            } else {
                mp[key] = i;
            }
        }
        
        mx = max(mx, solve(s, 'a', 'b', 'c'));
        mx = max(mx, solve(s, 'a', 'c', 'b'));
        mx = max(mx, solve(s, 'b', 'c', 'a'));
        
        return mx;
    }
};