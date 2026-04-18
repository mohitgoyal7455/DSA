class Solution {
public:
    int mirrorDistance(int n) {
        string c=to_string(n);
        reverse(c.begin(),c.end());
        int d=stoi(c);
        return abs(n-d);
    }
};