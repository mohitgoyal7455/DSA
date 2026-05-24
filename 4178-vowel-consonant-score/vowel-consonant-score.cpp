class Solution {
public:
    int vowelConsonantScore(string s) {
        int countv=0;
         int count=0;
        for(char it:s){
            if(it=='o' || it=='e' || it=='a' || it=='i' || it=='u'){
                countv++;
            }
            else if((it >= 48 && it <= 57) || it == ' '){
                continue;
            }
            else{
                count++;
            }
        }
        if(count ==0){
            return 0;
        }
        return floor (countv/count);
    }
};