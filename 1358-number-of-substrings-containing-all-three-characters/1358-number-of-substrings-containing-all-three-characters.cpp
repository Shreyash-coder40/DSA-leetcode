class Solution {
public:
    int numberOfSubstrings(string s) {
        std::vector<int> counts(3, 0); // index 0='a', 1='b', 2='c'
        int left = 0;
        int result = 0;
        int n = s.length();
        
        for (int right = 0; right < n; ++right) {
            // Expand the window
            counts[s[right] - 'a']++;
            
            // Shrink the window while all three characters are present
            while (counts[0] > 0 && counts[1] > 0 && counts[2] > 0) {
                // If s[left...right] is valid, then s[left...right], 
                // s[left...right+1], ..., s[left...n-1] are all valid.
                result += n - right;
                
                // Remove the leftmost character and shrink the window
                counts[s[left] - 'a']--;
                left++;
            }
        }
        
        return result;
    }
};