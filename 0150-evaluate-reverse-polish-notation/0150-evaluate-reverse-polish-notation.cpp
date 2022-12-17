class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long >s;
        for(auto x: tokens){
            if(x=="+" or x=="-" or x=="*" or x=="/"){
                long long c1=s.top(); s.pop();
                long long c2=s.top(); s.pop();
                if(x=="+") s.push(c1+c2);
                else if(x=="-") s.push(c2-c1);
                else if(x=="*") s.push(c1*c2);
                else if(x=="/") s.push(c2/c1);
                //s.push(c1);      
            }
            else s.push(stoi(x));
        }
        return s.top();
    }
};