class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int max_num = *max_element(nums.begin(),nums.end());
        int min_num = *min_element(nums.begin(),nums.end());
        vector<int> missing_element ;

        for (int i = min_num ; i<=max_num ; i++){
            if (find(nums.begin(), nums.end(), i) == nums.end()){
                missing_element.push_back(i);
            }
        }
        return missing_element;

    }
};