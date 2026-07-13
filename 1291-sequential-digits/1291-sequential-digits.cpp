#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> sequentialDigits(int low, int high) {
        std::vector<int> result;
        for (int start = 1; start <= 9; ++start) {
            long long num = start;
            int next_digit = start + 1;
            
            
            while (next_digit <= 9) {
                num = num * 10 + next_digit;
             
                if (num >= low && num <= high) {
                    result.push_back(num);
                }
                
                next_digit++;
            }
        }
        
        
        sort(result.begin(), result.end());
        
        return result;
    }
};