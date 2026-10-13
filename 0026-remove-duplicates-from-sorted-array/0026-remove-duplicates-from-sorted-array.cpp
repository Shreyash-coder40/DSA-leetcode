class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
     vector<int> expected_nums ;
     set<int> s1 ;
     for (int i = 0 ; i<nums.size(); i++){
        s1.insert(nums[i]);
     }

     int k = s1.size();

    for (auto elements : s1){
        expected_nums.push_back(elements);
    }
    sort(expected_nums.begin(),expected_nums.end());

    for (int i = 0 ; i < k ; i++){
        nums[i]=expected_nums[i];
    }

    return expected_nums.size();
    }
};