class Solution {
public:
    long long sumAndMultiply(int n) {
        
        long long sum=0;
        string num="";
        string temp= to_string(n);
        if (n==0) return 0;
        for (auto ch:temp){
          int digit= ch-'0';
          if (digit!=0){
            num+=ch;
            sum+=digit;
          }
        }
        long long multiple =sum *stoll(num);
        return multiple;
    }
};