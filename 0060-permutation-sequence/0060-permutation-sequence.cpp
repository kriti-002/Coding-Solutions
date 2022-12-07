class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>nums; int fact=1;
        for(int i=1; i<n; i++){
            fact*=i;
            nums.push_back(i);
        }
        nums.push_back(n);
        string res="";
        k=k-1;
        while(1){
            res+= to_string(nums[k/fact]);
            nums.erase(nums.begin() + k/fact);
            if(nums.size()==0) break;
            k%=fact;
            fact/=nums.size();
        }
        return res;
    }
};