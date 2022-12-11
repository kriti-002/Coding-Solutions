class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m=version1.length(), n=version2.length();
        int i=0, j=0;
        int t1=0,t2=0;
        while(i<m or j<n){
            while(i<m and version1[i]!='.'){
                t1= t1*10 +(version1[i]-'0');
                i++;
            }
            while(j<n and version2[j]!='.'){
                t2= t2*10 +(version2[j]-'0');
                j++;
            }
            if(t1 > t2) return 1;
            if(t1 < t2) return -1;
            t1=0; t2=0; i++; j++;
        }
        return 0;
    }
};