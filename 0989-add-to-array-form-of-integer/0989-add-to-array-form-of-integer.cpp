class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n=num.size(), K=k, i=n-1;
        while(K>0 and i>=0){
            num[i]+=K;
            K=num[i]/10;
            num[i]%=10; 
            i--;
        }
        while(K){
            num.insert(num.begin(),K%10);
            K/=10;
        }
        return num;
    }
};