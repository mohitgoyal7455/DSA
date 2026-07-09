class Solution {
public:
    long long reverse(int x) {
        long long ans=0;
        while(x!=0){
            int digit=x%10;

            ans=ans*10+digit;
            if(ans>INT_MAX || ans<INT_MIN){
                return 0;
            }
            x=x/10;
        }
        return ans;
    }
};