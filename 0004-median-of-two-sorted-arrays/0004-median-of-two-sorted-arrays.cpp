class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int length_of_v1=nums1.size();
        int length_of_v2=nums2.size();
        vector <int> merged_vector={};
        int i=0;
        int j=0;
        while (i<length_of_v1 && j<length_of_v2){
            if (nums1[i]<nums2[j]){
                merged_vector.push_back(nums1[i]);
                i++;
            }else{
                merged_vector.push_back(nums2[j]);
                j++;
            }

        }

        while (i<length_of_v1){
            merged_vector.push_back(nums1[i]);
            i++;
        }

        while (j<length_of_v2){
            merged_vector.push_back(nums2[j]);
            j++;
        }

        int length_of_merged_vector=merged_vector.size();
        int mid = length_of_merged_vector/2;
        if (length_of_merged_vector%2==0){
            return (double)((merged_vector[mid-1]+merged_vector[mid])/2.0);
        }else{
            return (double) (merged_vector[mid]);
        }

    }
};