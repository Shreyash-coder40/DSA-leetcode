class Solution {
public:
    double myPow(double x, int n) {
       
       long long binForm=n;
       double ans=1;
       if (n<0){
        x=1.0/x;
        binForm=-binForm;

       }
       
       while (binForm>0){

        if (binForm%2==1){
            ans= ans * x;
        }
            x*=x;
            binForm/=2;
       }
       return ans;
    }
};