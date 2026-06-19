class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s1;
        for (int i=0;i<nums.size();i++){
            s1.insert(nums[i]);
        }
        int index=0;
        for (int n:s1){
            nums[index]=n;
            index++;
        }
        return s1.size();


    }
};