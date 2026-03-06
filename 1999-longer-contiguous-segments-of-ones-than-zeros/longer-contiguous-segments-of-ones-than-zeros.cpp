class Solution {
public:
    bool checkZeroOnes(string s) {
       int i = 0;
       int count1 = 0;
       int count0 = 0;
       int max1 = 0;
       int max0 = 0;
       int n = s.length();

       while(i < n){
            if(s[i] == '1'){
                count1 = 0;
                while(i < n && s[i] == '1'){
                    count1++;
                    i++;
                }
                max1 = max(max1, count1);
            }
            else{
                count0 = 0;
                while(i < n && s[i] == '0'){
                    count0++;
                    i++;
                }
                max0 = max(max0, count0);
            }
       }

       return max1 > max0;
    }
};