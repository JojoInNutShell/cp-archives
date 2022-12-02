class Solution {
private :
    long long dp[1006][4];
public:
    int numTilings(int n) {
        memset(dp, 0, sizeof(dp));
        dp[1][0] = 1;
        dp[1][3] = 1;
        for(int i = 2; i <= n; ++i) {
            dp[i][0] += (dp[i - 1][3]) % (1000000007);
            
            dp[i][1] += (dp[i - 1][0] + dp[i - 1][2]) % (1000000007);
            
            dp[i][2] += (dp[i - 1][0] + dp[i - 1][1]) % (1000000007);
            
            dp[i][3] += (dp[i - 1][3] + dp[i - 1][2] + dp[i - 1][1] + dp[i - 1][0]) % (1000000007);
        }
        return dp[n][3] % (1000000007);
    }
};