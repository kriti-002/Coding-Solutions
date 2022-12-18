class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>res(temperatures.size(),0);
        stack<int>s;
        for(int i=0; i<temperatures.size(); i++){
            while(!s.empty() and temperatures[s.top()]<temperatures[i]){
                int x=s.top();
                res[x]=i-x;
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};