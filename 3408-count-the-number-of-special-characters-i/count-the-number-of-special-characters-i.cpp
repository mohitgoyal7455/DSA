class Solution {
public:
    int numberOfSpecialChars(string words) {
        int n = words.size();
        unordered_set<char> hash;
        int count=0; 
        for(int i=0;i<n;i++){ 
            if(hash.find(words[i])==hash.end()){ 
                if(hash.find(words[i]+32)!=hash.end() || hash.find(words[i]-32)!=hash.end()){ 
                count++ ;
                }
                hash.insert(words[i]); 
            }            
        }
        return count; 
    }
};