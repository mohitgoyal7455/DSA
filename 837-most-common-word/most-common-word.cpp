class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string,int>mp;
         string word;
         paragraph += ' ';
        for(char c:paragraph){
            if (isalpha(c)){
                word += tolower(c);
             }
            else if (!word.empty()) {
                    mp[word]++;
                    word.clear();
                }
        }
        for(string b:banned){
            mp.erase(b);
        }
        int maxi=0;
        for (auto it : mp) {
    if (it.second > maxi) {
        maxi = it.second;
        word = it.first;
            }
        }
        return word;
        
    }
};