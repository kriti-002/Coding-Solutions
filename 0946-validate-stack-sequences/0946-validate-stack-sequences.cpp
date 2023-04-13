class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int i=0, j=0, n=pushed.size();
        while(i<n){
            st.push(pushed[i]); i++;
            while(st.size()> 0 and st.top()== popped[j]){
                st.pop(); j++;
            }
        }
        return st.empty();
    }
};