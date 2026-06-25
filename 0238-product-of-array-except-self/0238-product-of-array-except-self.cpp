class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        
        int ans=1;
        vector<int>result(nums.size(),1);
        for (int i=1;i<nums.size();i++){
            
            ans = ans * nums[i-1];
            result[i]=ans;
        }

        ans=1;
        int n=nums.size();
        for (int i=nums.size()-2;i>=0;i--){
            ans= ans * nums[i+1];
            result[i]=result[i]*ans;
        }

        return result;
    }
};