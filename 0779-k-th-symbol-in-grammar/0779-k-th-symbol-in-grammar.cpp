class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1) return 0;
        
        int tot= pow(2, (n-1))/2;
        if(k> tot) return 1- kthGrammar(n, k-tot);
        return kthGrammar(n-1, k);
        
    }
};