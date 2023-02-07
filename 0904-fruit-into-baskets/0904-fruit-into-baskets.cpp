class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int len=0, n=fruits.size(), i=0, j=0;
        if(n==1) return 1;
        unordered_map<int, int>mp;
        
        while(j<n){
            mp[fruits[j]]++;
            if(mp.size() >2){
                if(mp[fruits[i]]==1){
                    mp.erase(fruits[i]);
                }else{
                    mp[fruits[i]]--;
                }
                i++;
            } 
            len=max(len, j-i+1);
            j++;
        }
        return len;
    }
};