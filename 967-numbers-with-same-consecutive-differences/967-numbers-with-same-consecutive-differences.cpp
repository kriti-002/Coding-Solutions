class Solution {
public:
    void help(int n, int src,int k, vector<int>&res){
        if(n==0) res.push_back(src);
        else{
            int dig=src%10;
            if(dig + k <= 9){
                help(n-1, src*10+dig+k, k, res);
            }
            if(k != 0 and dig >= k){
                help(n-1, src*10+dig-k, k,res);
            }   
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>res; 
        
        for(int i=1; i<=9; ++i){
            help(n-1,i,k,res);
        }
        return res;
    }
};