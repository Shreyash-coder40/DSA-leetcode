class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       
       int l = 0 ;
       int r = 0 ;
       int n = fruits.size();
       int max_len = 0 ;
       unordered_map<int,int> basket ;
       while ( r < n){
        
            basket[fruits[r]]++ ;

            if (basket.size() > 2){
                basket[fruits[l]]--;
                if (basket[fruits[l]] == 0 ){
                    basket.erase(fruits[l]);
                }
                l++;
            }

            if (basket.size() <=2){
                max_len = max(max_len , r-l+1);
            }
        
            r++;

       }

       return max_len ;
        
    }

};