class Solution {
public:
    string nearestPalindromic(string s) {
        int n=s.length();
        long no=stol(s);
        set<long> candidates;
        long c=pow(10,n)+1;
        candidates.insert(c);
        c=pow(10,n-1)-1;
        candidates.insert(c);
        
        long pre=stol(s.substr(0,(n+1)/2));
        for(int i=-1;i<=1;i++){
            string p=to_string(pre+i);
            string z;
            if(n&1)
                z=p.substr(0,p.length()-1);
            else
                z=p;
            reverse(z.begin(),z.end());
            p+=z;
            // cout<<"p= "<<p<<endl;
            long pp=stol(p);
            candidates.insert(pp);
        }
        long ans;
        long diff=LONG_MAX;
        
        candidates.erase(no);
       
        for(auto it:candidates){
            if(abs(no-it)<diff){
                ans=it;
                diff=abs(no-it);
            }
        }
        return to_string(ans);
    }
};