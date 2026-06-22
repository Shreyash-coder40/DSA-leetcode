class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(5,0);
        
        for (char ch:text){
            if (ch=='b'){
                freq[0]++;
            }
            if (ch=='a'){
                freq[1]++;
            }
            if (ch=='l'){
                freq[2]++;
                
            }
            if (ch=='o'){
                freq[3]++;
                
            }
             if (ch=='n'){
                freq[4]++;
            }
        }
        freq[2] /= 2;
        freq[3] /= 2;

        return min({freq[0], freq[1], freq[2], freq[3], freq[4]});
        
    }
};