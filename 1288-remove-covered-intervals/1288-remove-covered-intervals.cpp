class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // 1. Sort: start ascending, end descending
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });

        int count = 0;
        int max_end = 0;

        // 2. Traverse
        for (const auto& interval : intervals) {
            if (interval[1] > max_end) {
                count++;
                max_end = interval[1];
            }
        }
        return count;
    }
};