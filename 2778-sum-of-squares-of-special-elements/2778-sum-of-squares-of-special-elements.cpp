class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        vector<int> special_num;
        int n = nums.size();
        for (int i = 1 ; i<=n ; i++){
            if (n % i  == 0){
                special_num.push_back(nums[i-1]);
            }
        }

        int sum = 0;
        for (int i = 0 ; i<special_num.size(); i++){
            int num = special_num[i];
            sum = sum + (num*num);
        }
        return sum;
    }
};