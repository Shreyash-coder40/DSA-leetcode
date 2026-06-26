class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        
        int offset = n + 1;
        vector<int> bit(2 * n + 2, 0);
        
        auto update = [&](int idx, int val) {
            for (; idx < bit.size(); idx += idx & -idx)
                bit[idx] += val;
        };
        
        auto query = [&](int idx) {
            int sum = 0;
            for (; idx > 0; idx -= idx & -idx)
                sum += bit[idx];
            return sum;
        };
        
        long long ans = 0;
        int current_sum = 0;
        
        
        update(0 + offset, 1);
        
        for (int x : nums) {
            current_sum += (x == target ? 1 : -1);
           
            ans += query(current_sum + offset - 1);
            
            update(current_sum + offset, 1);
        }
        
        return ans;
    }
};