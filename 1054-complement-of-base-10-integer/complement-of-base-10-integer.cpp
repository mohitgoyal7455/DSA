class Solution {
public:
    int bitwiseComplement(unsigned n) {
        if (n == 0) return 1;
        int mask=1;
        while(mask<n){
            mask=(mask<<1)+1;
        }
        return    mask^n;
    }
};
