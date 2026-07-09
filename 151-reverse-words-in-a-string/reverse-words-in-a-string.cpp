class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        string word="";
        string w="";
        for(char c :s){
            if(c!=' '){
                word.push_back(c);
            }
          else {
            if(!word.empty()){
                st.push(word);
                word="";
            }

          }
        }
         if (!word.empty()){
            st.push(word);}

        while(!st.empty()){
            w+=st.top();
            st.pop();
        
        if(!st.empty()){
           
            w+=" ";
        }
    }
        return w;
        
        
    }
};