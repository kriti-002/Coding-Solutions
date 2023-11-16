class Solution {
    string help(string curr, unordered_set<string>&st, int n){
        if(curr.size()==n){
            if(st.find(curr)== st.end()) return curr;
            return "";
        }
        string zero= help(curr+"0", st, n);
        if(zero.size()>0) return zero;
        return help(curr+"1", st, n);
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> st(nums.begin(), nums.end());
        return help("", st, nums.size());
    }
};