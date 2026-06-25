class Solution {
public:
    int minMoves(vector<int>& nums) {
        int total_moves=0;
        int max_element=0;
        for (int i=0;i<nums.size();i++){
            max_element=max(max_element,nums[i]);
        }
        
        for (int i=0;i<nums.size();i++){
            total_moves+=max_element-nums[i];
        }
        return total_moves;
    }
};