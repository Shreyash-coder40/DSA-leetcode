class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum=0;
        int max=nums[0];
        for (int i=0;i<nums.size();i++){
            currentSum+=nums[i];

            if (currentSum > max) {
                max = currentSum;
            }

            if (currentSum < 0) {
                currentSum = 0;
            }
        }
        return max;
    }
};