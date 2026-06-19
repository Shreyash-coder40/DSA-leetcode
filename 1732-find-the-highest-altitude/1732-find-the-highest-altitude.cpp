class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> net_gain={0};
        for (int i=0;i<gain.size();i++){
            int sum=net_gain[i]+gain[i];
            net_gain.push_back(sum);
        }

        int largest_element=net_gain[0];
        for (int i=0;i<net_gain.size();i++){
            if (net_gain[i]>largest_element){
                largest_element=net_gain[i];
            }
            
        }
        return largest_element;
    }
};