class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int num = 1;
        
        while (top <= bottom && left <= right) {
            // 1. Traverse from Left to Right along the top row
            for (int col = left; col <= right; ++col) {
                matrix[top][col] = num++;
            }
            top++;
            
            // 2. Traverse from Top to Bottom along the right column
            for (int row = top; row <= bottom; ++row) {
                matrix[row][right] = num++;
            }
            right--;
            
            // 3. Traverse from Right to Left along the bottom row
            if (top <= bottom) {
                for (int col = right; col >= left; --col) {
                    matrix[bottom][col] = num++;
                }
                bottom--;
            }
            
            // 4. Traverse from Bottom to Top along the left column
            if (left <= right) {
                for (int row = bottom; row >= top; --row) {
                    matrix[row][left] = num++;
                }
                left++;
            }
        }
        
        return matrix;
    }
};