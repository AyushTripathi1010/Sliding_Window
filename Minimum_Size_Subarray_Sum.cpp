// LeetCode Link: https://leetcode.com/problems/minimum-size-subarray-sum/description/


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
         
         int n = nums.size();
         int l = 0, r = 0, len = INT_MAX, sum =0;

         while(r < n)
         {     
              if(len == 1) break; // We can't get anything minimum than 1.
             if(sum + nums[r]>= target)
             {
                 sum+= nums[r];

                 while(true)
                 {
                     if(sum-nums[l] >= target)
                     {
                         sum-= nums[l];
                         l++;
                     }
                     else break;

                 }

                 len = min(len , r-l+1);
                 r++;
             }
             else
             {
                 sum+= nums[r];
                 r++;
             }
         }

         return len == INT_MAX ? 0 : len;
    }
};