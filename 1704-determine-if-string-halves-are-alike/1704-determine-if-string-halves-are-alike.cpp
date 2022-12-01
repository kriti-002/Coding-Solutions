class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<int> st {'a','e','i','o','u','A','E','I','O','U'};
        int c1=0, c2=0, n=s.length();
        for(int i=0; i<n/2; i++){
            if(st.find(s[i])!= st.end()) c1++;
        }
        for(int i=n/2; i<n; i++){
            if(st.find(s[i])!= st.end()) c2++;
        }
        return c1==c2;
    }
};