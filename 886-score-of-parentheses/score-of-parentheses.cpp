class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        
        for (char ch : s) {
            if (ch == '(') {
                st.push(-1);
            } else {
                
                if (st.top() == -1) {
                    st.pop();
                    st.push(1);
                } else {
                    
                    int val = 0;
                    while (st.top() != -1) {
                        val += st.top();
                        st.pop();
                    }
                    st.pop(); 
                    st.push(2 * val); 
                }
            }
        }
        
        
        int totalScore = 0;
        while (!st.empty()) {
            totalScore += st.top();
            st.pop();
        }
        
        return totalScore;
    }
};