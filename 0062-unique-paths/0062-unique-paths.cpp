class Solution {
public:
    int uniquePaths(int m, int n) {
        int mini=min(m,n);
        if(mini==m)
        {
            vector<int>v(m,1);
            int current=1;
            for(int j=n-2;j>=0;j--)
            {
                current=1;
                for(int i=m-2;i>=0;i--)
                {
                    v[i]+=current;
                    current=v[i];
                }
            }
            return current;
        }
        else
        {
            vector<int>v(n,1);
            int current=1;
            for(int j=m-2;j>=0;j--)
            {
                current=1;
                for(int i=n-2;i>=0;i--)
                {
                    v[i]+=current;
                    current=v[i];
                }
            }
            return current;
        }
    }
};