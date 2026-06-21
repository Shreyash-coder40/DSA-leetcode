class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int money_left = coins;
        int count=0;
        for (int i=0;i<costs.size();i++){
            if (money_left==0||money_left<costs[i] ){
                break;
            }else if (money_left>=costs[i]){
                count++;
                money_left-=costs[i];
            }

        }
        return count;
    }
};