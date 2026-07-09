class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char ,int>mp;
        for(char it:stones){
            mp[it]++;
        }
        int count=0;
        for(char it:jewels){
            count+=mp[it];
        }
        return count;
    }
};