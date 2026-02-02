class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ans(nums2.size(), 0);
        vector<int> ans2;
        stack<int> st;

        for(int i = nums2.size() - 1; i >= 0; i--) {
            while(st.size() > 0 && st.top() <= nums2[i]) {
                st.pop();
            }

            if(st.size() == 0) {
                ans[i] = -1;
            }
            else {
                ans[i] = st.top();
            }

            st.push(nums2[i]);
        }

        for(int i = 0; i < nums1.size(); i++) {
            for(int j = 0; j < nums2.size(); j++) {
                if(nums1[i] == nums2[j]) {
                    ans2.push_back(ans[j]);
                    break;
                }
            }
        }

        return ans2;
    }
};
