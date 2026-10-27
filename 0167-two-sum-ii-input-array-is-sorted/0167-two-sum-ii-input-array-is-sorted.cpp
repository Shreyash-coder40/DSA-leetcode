class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            
            if (sum == target) {
                // The problem requires 1-indexed answers
                return {left + 1, right + 1}; 
            } else if (sum < target) {
                left++; // We need a larger sum, move the left pointer right
            } else {
                right--; // We need a smaller sum, move the right pointer left
            }
        }
        
        return {}; 
    }
};