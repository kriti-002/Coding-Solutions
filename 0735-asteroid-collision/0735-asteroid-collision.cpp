class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        
        stack<int>s;
        for(int i=0; i<a.size(); i++){
            bool flag=1;
            while(!s.empty() and (s.top()> 0 and a[i]<0)) {
                if(abs(s.top()) < abs(a[i])){
                    s.pop();
                    continue;
                }else if(abs(s.top())== abs(a[i])) s.pop();
                flag=0;
                break;
            }
            if(flag) s.push(a[i]);
            
        }
        vector<int>res(s.size());
        int i=s.size()-1;
        while(i>=0){
            res[i]=(s.top());
            s.pop();
            i--;
        }
        return res;
    }
};