class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int ans=nums[0];
        int freqCount=1;
        int n=nums.size();

        for (int i=1;i<nums.size();i++){
            if (nums[i-1]==nums[i]){
                freqCount+=1;
            }else{
                freqCount=1;
                ans=nums[i];
            }

            if (freqCount>n/2){
                return ans;
            }
        }
        return ans;
    }
};