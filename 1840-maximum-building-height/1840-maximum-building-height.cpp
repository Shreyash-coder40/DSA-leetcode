class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
       
        restrictions.push_back({1, 0});
        sort(restrictions.begin(), restrictions.end());
        
        int m = restrictions.size();
        
      
        if (restrictions.back()[0] != n) {
            restrictions.push_back({n, n - 1});
        }
        m = restrictions.size();

        
        for (int i = 1; i < m; ++i) {
            restrictions[i][1] = min(restrictions[i][1], 
                                     restrictions[i-1][1] + (restrictions[i][0] - restrictions[i-1][0]));
        }

        
        for (int i = m - 2; i >= 0; --i) {
            restrictions[i][1] = min(restrictions[i][1], 
                                     restrictions[i+1][1] + (restrictions[i+1][0] - restrictions[i][0]));
        }

        
        int maxHeight = 0;
        for (int i = 0; i < m - 1; ++i) {
            int id1 = restrictions[i][0], h1 = restrictions[i][1];
            int id2 = restrictions[i+1][0], h2 = restrictions[i+1][1];
            
            int dist = id2 - id1;
           
            int currentPeak = (dist + h1 + h2) / 2;
            maxHeight = max(maxHeight, currentPeak);
        }

        return maxHeight;
    }
};