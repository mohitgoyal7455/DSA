class Solution {
public:
    int findComplement(int num) {
        int mask=1;
        while(mask<num){
            mask=(mask<<1)+1;
        }
        num=num^mask;
        return num;
        
    }
};