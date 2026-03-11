class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even = 0, odd = 0;
        for(int i = 0; i <= log2(n); ++i){
            if(n & (1 << i)){
                if(i%2) odd++;
                else even++;
            }
        }
        return {even, odd};
    }
};