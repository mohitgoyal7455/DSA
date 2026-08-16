class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;

        double n = x;

        for (int i = 0; i < 20; i++) {
            n = (n + x / n) / 2;
        }

        return (int)n;
    }
};