class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> prefix={1};
        vector<int> suffix={1};
        int ans=1;
        vector<int>result;
        for (int i=1;i<nums.size();i++){
            ans = ans * nums[i-1];
            prefix.push_back(ans);
        }

        ans=1;
        int n=nums.size();
        for (int i=nums.size()-2;i>=0;i--){
            ans= ans * nums[i+1];
            suffix.push_back(ans);
        }

       

        for(int i=0; i<prefix.size();i++){
            int a=prefix[i]*suffix[n-i-1];
            result.push_back(a);
        }
        return result;
    }
};