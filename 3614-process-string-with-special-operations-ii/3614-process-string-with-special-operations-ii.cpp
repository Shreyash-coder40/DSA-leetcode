class Solution {
public:
    char processStr(string s, long long k) {
        int n=s.size();
        long long len=0;
        for (char & ch : s){
            if (ch=='*'){
                if (len>0){
                    len--;
                }
            }else if (ch=='#'){
                len*=2;
            } else if (ch=='%') {
                continue;
                }
            else{
                // character count a to z
                len++;
            }
        }

        if (k>=len){
            return '.';
        }

        for (int i=n-1;i>=0;i--){
            char ch=s[i];
            if (ch=='*'){
                len++;
            }else if (ch=='%'){
                k=len-k-1;
            }else if (ch=='#'){
                len/=2;
                if (k>=len){
                    k=k-len;
                }
            }else{
                len--;
                if (len==k){
                return ch;
            }
            }
           
        }
        return '.';
    }
};