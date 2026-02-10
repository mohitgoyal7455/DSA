class Solution {
public:
    string decodeString(string s) {
        stack<int>number;
        stack<string>str;
        int num=0;
        string curr="";
        for(char ch:s){
            if(isdigit(ch)){
                num=num*10+(ch - '0');
            }
            else if(ch=='['){
                number.push(num);
                str.push(curr);
                num=0;
                curr="";

            }
            else if(ch==']'){
                int times=number.top();
                number.pop();
                string prev=str.top();
                str.pop();


                string temp="";
                for(int i=0;i<times;i++){
                    temp=temp+curr;
                }
                curr=prev+temp;
            }
            else {
                curr=curr+ch;
            }
            




        }
        return curr;
    }
};