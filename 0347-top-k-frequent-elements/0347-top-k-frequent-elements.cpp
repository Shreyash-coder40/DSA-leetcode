class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for (int i = 0 ; i<nums.size() ; i++){
            freq[nums[i]]++;
        }

        vector<pair<int,int>> ans;
        for (auto pair : freq){
            ans.push_back({pair.second,pair.first});
        }
        
        int m = ans.size() ;
        sort(ans.begin(),ans.end());
        vector<int> ans1;
        int i = 0 ;
        while (k --){
            ans1.push_back(ans[m-i-1].second);
            i++;
        }

        return ans1;
    }
};