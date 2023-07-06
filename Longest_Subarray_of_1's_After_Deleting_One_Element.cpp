// LeetCode Link: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/

class Solution {
public:

    // Note: here the catch is that we have to maintain a sliding window of with at most 
     // 1 zero and one thing to remember is we have to delete any 1 element.

     // For eg: for the testcase:  nums = [1,1,1] , max size will be 2 since we have to delete one element
    int longestSubarray(vector<int>& nums) {
          
          int cnt0 = 0;
          int l =0 , r=0;
          int len=0;
          int n = nums.size();

          while(r < n)
          {
              if(nums[r] == 0 && cnt0 ==0)
              {
                  cnt0++;
                  r++;
              }
              else if(nums[r] == 0 && cnt0 ==1)
              {
                  while(cnt0!=0)
                  {
                      if(nums[l] ==0) cnt0--;

                      l++;
                  }
              }
              else
              {
                 if(cnt0 == 0) 
                 {
                     if(r!= n-1) len = max(len , r-l+1);
                     else
                     len = max(len , r-l);
                 }

                 if(cnt0 == 1) len = max(len , r-l);

                  r++;
              }
          }

          return len;
    }
};