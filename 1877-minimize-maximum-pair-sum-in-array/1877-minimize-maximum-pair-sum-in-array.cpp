class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int left=0;
        int right=nums.size()-1;
        int max=0;
        while (left<right){
            int currentSumValue=nums[left]+nums[right];

            if (currentSumValue>max){
                max=currentSumValue;
            }
            left++;
            right--;
        }
        return max;
    }
};