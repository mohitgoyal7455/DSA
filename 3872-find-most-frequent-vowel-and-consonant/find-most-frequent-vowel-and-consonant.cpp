class Solution {
public:
    int maxFreqSum(string s) {
        int count =0;
        unordered_map<char,int>mp;
        unordered_map<char,int>co;
        for(char c:s){
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
                mp[c]++;
            }
            else{
                co[c]++;

            }
        }
            int maxi1 = 0;
            int maxi2 = 0;

      for (auto it : mp) {
         maxi1 = max(maxi1, it.second);
        }
        for (auto it : co) {
         maxi2 = max(maxi2, it.second);
        }

        return maxi1+maxi2;
    }
};