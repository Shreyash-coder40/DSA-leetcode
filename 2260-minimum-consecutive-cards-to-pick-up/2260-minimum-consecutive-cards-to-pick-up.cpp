class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int , int> m1 ;

        int  r = 0;
        int n = cards.size();
        int min_len = INT_MAX;
        while (r <n){
            if (m1.find(cards[r]) != m1.end()){
                int l = m1[cards[r]];
                min_len = min(min_len , r-l+1);
            }

            m1[cards[r]] = r;
            r++;
        }
        if (min_len == INT_MAX){
            return -1 ;
        }else{
            return min_len ;
        }
    }
};