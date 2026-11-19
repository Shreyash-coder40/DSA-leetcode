class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        

        int n = nums2.size();
        stack<int> stk;
        unordered_map<int,int> map;
        for (int i = n-1 ; i>=0 ; i--){
            
            while (!stk.empty() && stk.top()<nums2[i]){
                stk.pop();
            }
            if (!stk.empty()){
                map[nums2[i]]= stk.top();
            }else{
                map[nums2[i]]= -1;
            }
            stk.push(nums2[i]);
        }

        int m = nums1.size();
        vector<int> ans ;
        for (int i = 0 ; i< m ;i++){
            ans.push_back(map[nums1[i]]);
        }
        return ans;

    }
};