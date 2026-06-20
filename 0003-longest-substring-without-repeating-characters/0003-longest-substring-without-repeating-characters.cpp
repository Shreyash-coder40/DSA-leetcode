class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int count[128] = {0}; 
        int left = 0, right = 0, maxLen = 0;
        int n = s.length();

        while (right < n) {
            
            char rChar = s[right];
            count[rChar]++;

           
            while (count[rChar] > 1) {
                char lChar = s[left];
                count[lChar]--;
                left++;
            }

           
            maxLen = max(maxLen, right - left + 1);
            
           
            right++;
        }

        return maxLen;
    }
};