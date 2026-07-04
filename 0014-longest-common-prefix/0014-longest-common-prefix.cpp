class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        // Iterate through each character of the first string
        for (int i = 0; i < strs[0].length(); i++) {
            char c = strs[0][i];
            
            // Compare this character with the same index in all other strings
            for (int j = 1; j < strs.size(); j++) {
                // If we reach the end of a string or find a mismatch
                if (i == strs[j].length() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        
        return strs[0];
    }
};