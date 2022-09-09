class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end());
        
        int n=properties.size();
        int ans=0,a=properties[n-1][0],b=properties[n-1][1],lmax=properties[n-1][1];
        
        for(int i=n-2;i>=0;i--){
            if(properties[i][0]< properties[i+1][0]) {
                b=max(lmax,b);
               lmax=max(b,properties[i][1]); 
            }
            if(properties[i][0]<a and properties[i][1]<b)
              ans++;
        }
        return ans;
    }
};