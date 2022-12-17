
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        long long res = 0;
        if(heights.empty()) return res;
            
        stack<long long> st;
        
        for(int i=0; i<heights.size(); ++i) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                long long last = st.top();
                st.pop();
                long long curr = heights[last] * (st.empty() ? i : (i - st.top() - 1));
                res = max(res, curr);
            }
            st.push(i);
        }
        while(!st.empty()) {
            long long last = st.top();
            st.pop();
            long long curr = heights[last] * (st.empty() ? heights.size() : (heights.size() - st.top() -1));
            res = max(res, curr);
        }
        return (int)res;
    }
};