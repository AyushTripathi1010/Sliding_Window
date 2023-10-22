// Problem Link: https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-125/problems 

// INTUITION: So the Geek want's to give k conecutive cholcates to the winner, and he want the maximum unique flavour
// he can have for himself after giving any k consecutive chocolates

// Eg: flavors = [1,2,2,3,4,3], N = 6, K = 3.
// Ans.) IF geek gives the candies in range [1,3] inclusive
// with flavors [2,2,3], he can get 3 unique flavors candies.[1,4,3].

// SO we are using map to store the count of each chocolates, and using sliding window
// we are reducing the frequecny of chocolate at index , and at any point candies become 0, we remove
// that particular candy from our map for now, and as soon that particular index is not part of our window, then we
// will increment the count of that candy again using 'l' pointer.
class Solution {
  public:
    int maximizeFlavors(vector<int>& candies, int k) {
        
        int n = candies.size();
         int ans = 0;
        unordered_map<int,int> m;
        for(int &elem : candies) m[elem]++;
       
        for(int i =0 ; i < k ;i++)
        {
            
            if(--m[candies[i]] == 0) m.erase(candies[i]);
        }
        
        int sz = m.size();
        ans = max(ans,sz);
        
        int l = 0 , r = k;
        
        while(r < n)
        {
            m[candies[l++]]++;
            
            
            if(--m[candies[r]] == 0) m.erase(candies[r]);
            
            r++;
            int sz = m.size();
            ans = max(ans, sz);
        }
        
        return ans;
    }