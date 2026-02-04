class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        dp[0][0] = 1;
        for(int i=0; i<m; i++) {
            if(p[i] == '*') dp[0][i+1] = dp[0][i];
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(s[i] == p[j] || p[j] == '?') {
                    dp[i+1][j+1] = dp[i][j];
                } else if(p[j] == '*') {
                    dp[i+1][j+1] = dp[i][j+1] || dp[i+1][j];
                }
            }
        }
        return dp[n][m];
    }
};