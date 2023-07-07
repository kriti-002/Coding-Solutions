class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k, int i=0, int j=0) {
        if(k==0) return answerKey.length();
        string tmp="";
        int n=answerKey.length(), noTrue=0, noFalse=0, res=0;
        while(j<n){
            char cj= answerKey[j];
            cj=='T'? noTrue++: noFalse++;
            if(noTrue<=k or noFalse<=k) res=max(res, j-i+1);
            else{
                if(answerKey[i++]=='T') noTrue--;
                else noFalse--;
            }
            j++;
            
        }
        return res;
    }
};