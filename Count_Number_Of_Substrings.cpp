// Problem Link: https://practice.geeksforgeeks.org/problems/count-number-of-substrings4528/1 

// INTUITION : This questions wants us to find count of substrings with exactly k distinct
// characters, which is a bit complicated to find, but it is easier to find number of substrings
// with atmost k characters. 

// So this converts our question to:
// Cnt Substring with exact k character = cnt substring with at most k character - cnt substring with at most k-1 characters
// SO when we subtract it we get count of exact k character substrings.

// We are counting substrings by cnt += r-l+1;
// eg: abc= 'a' , 'b' , "ab", 'c' , "bc" , "abc".

// SO at every character index r-l+1 subtrings can be generated.

class Solution
{
  public:
    long long int solve(string &s , int k, int &n)
    {
        int temp = 0;
        int l =0 , r=0;
        long long int cnt =0 ;
        vector<int> freq(26, 0);
        while(r < n)
        {  
            if(freq[s[r] - 'a'] == 0) 
            {
                 temp++;   // count disinct characters
                 freq[s[r] - 'a']++;
                   
                 while( temp > k)  // left shifting done
                 {
                     if(--freq[s[l++] - 'a'] == 0)
                     temp--;
                     
                 }
            }
            else
            {
                freq[s[r] - 'a']++;
            }
            
            
                cnt= cnt+  (r-l+1); // counts numbe of substring 
                r++;
            
        }
        return cnt;
    }
    long long int substrCount (string s, int k) {
         
         int n = s.size();
         return solve(s, k, n)- solve(s , k-1 , n);
    }
};