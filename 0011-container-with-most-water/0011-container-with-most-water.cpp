class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area=0;
        int i=0;
        int j=height.size()-1;
        
        while (i<j){
            int length = min(height[i],height[j]);
            int distance = j-i;
            int area = length * distance;
             max_area=max(area,max_area);

            height[i]<height[j] ? i++ : j--;
        }

        return max_area;
    }
};