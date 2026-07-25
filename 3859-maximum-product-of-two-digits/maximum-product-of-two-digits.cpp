class Solution {
public:
    int maxProduct(int n) {
        vector<int>arr;
        while(n>0){
            int digit =n%10;
            arr.push_back(digit);
            n=n/10;

        }
        sort(arr.begin(),arr.end());
        int i=arr.size()-1;
        int j=arr.size()-2;
        return arr[i]*arr[j];
    }
};