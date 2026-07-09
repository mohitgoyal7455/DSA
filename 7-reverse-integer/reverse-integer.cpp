class Solution {
public:
    int reverse(int x) {
        bool neg = x < 0;

        string s = to_string(abs((long long)x));
        ::reverse(s.begin(), s.end());

        long long ans = stoll(s);

        if (neg) ans = -ans;

        return (ans > INT_MAX || ans < INT_MIN) ? 0 : ans;
    }
};