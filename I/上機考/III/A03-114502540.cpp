#include <bits/stdc++.h>
using namespace std;

const int MN = 15;

int main()
{
    int m,n; cin >> m >> n;
    int dp[MN][MN][2] = {1};    // 定義 dp[x][y][z] = 走到 x,y 的方法數, z = 1 : 上一步是往下
    for(int x=0; x <= m; ++x)
    {
        for(int y=0; y <= n; ++y)
        {   // 轉移
            if(y > 0) dp[x][y][0] += dp[x][y-1][0] + dp[x][y-1][1];
            if(y > 1) dp[x][y][0] += dp[x][y-2][0] + dp[x][y-2][1];
            if(x > 0) dp[x][y][1] += dp[x-1][y][0];
        }
    }
    cout << dp[m][n][0] + dp[m][n][1] << '\n';
}