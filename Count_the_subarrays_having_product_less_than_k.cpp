// GFG-LINK :https:practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1

// Note: Here the sliding window is of variable sie where it firt being expanded then ,
// shrinked
class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
           
           
           int l = 0 , r = 0, cnt=0;
           long long prod = 1;
           
           while( r< n)
           {
               if(prod *a[r] < k)
               {
                  prod*=a[r];
                  
                  cnt += r-l+1;
                  r++;
               }
               
               else
               {
                   if(prod!= 1) prod/= a[l];
                   
                   if(l == r) r++;
                   
                   l++;
                   
               }
           }
           
            
           return cnt;
    }
};