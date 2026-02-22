class Solution {
public:
    int binaryGap(int n) {

        int prev = -1;
        int i = 0;
        int maxlen = 0;

        while(n) {
            if (n & 1) {
                if (prev != -1) {
                    maxlen = max(maxlen, i - prev);
                }
                prev = i;
            }
            n >>=1;
            i++;
        }
        
        return maxlen;
    }
};