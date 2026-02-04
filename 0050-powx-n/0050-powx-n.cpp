class Solution {
public:
    double myPow(double x, int n) {
        int m=n;
        long long N=n;
        if(N<0)
        N=-N;
        double ans=1.0;
        while(N>0)
        {
            if(N%2==1)
            {
                ans*=x;
                N=N-1;
            }
            else
            {
                x=x*x;
                N=N/2;
            }
        }
        if(m<0)
        return 1.0/ans;
        return ans;
    }
};