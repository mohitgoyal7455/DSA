class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddn=n*n;
        int evenn=n*(n+1);
        return gcd(oddn,evenn);
        
    }
};