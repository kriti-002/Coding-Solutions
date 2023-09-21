class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int m=nums1.size(), n=nums2.size();
      vector<int> res;
      int i=0, j=0;
      while(i<m and j<n){
          if(nums1[i]== nums2[j]){
              res.push_back(nums1[i]);
              res.push_back(nums2[j]);
              i++; j++;
          }else if(nums1[i] > nums2[j]){
              res.push_back(nums2[j]);
              j++;
          }else{
              res.push_back(nums1[i]);
              i++;
          }
      }
      while(i<m){
          res.push_back(nums1[i]);
          i++;
      }
      while(j<n){
          res.push_back(nums2[j]);
          j++;
      }    
      int tot=m+n;
      double result=0;
      if(tot&1) result=res[tot/2];
      else result=(res[tot/2]+ res[tot/2-1])/(double)2;
      
      return result;  
    }
};