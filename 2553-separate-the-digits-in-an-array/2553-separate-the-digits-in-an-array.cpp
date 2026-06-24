class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            vector<int> temp;
            while (num > 0) {
                temp.push_back(num % 10);
                num /= 10;
            }
            // Reverse the digits extracted from the current number
            // to get them in the correct order
            for (int j = temp.size() - 1; j >= 0; j--) {
                ans.push_back(temp[j]);
            }
        }
        return ans;
    }
};