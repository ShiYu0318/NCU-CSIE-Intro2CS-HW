// Assignment A11-2
// Name: 黃士育
// Student Number: 114502540
// Course 2025-CE1003A-資工1A

#include <bits/stdc++.h>
using namespace std;
// #define fio ios_base::sync_with_stdio(0); cin.tie(0)

// 定義 dp[i][1/0] 為爬到第 i 階時 有/無 使用技能的走法數
// 轉移式：
// 1. dp[i][0] = 前兩階不管有無使用技能的走法數總和
// 2. dp[i][1] = 第 i-3 階沒使用技能的走法數
// 答案：第 n 階 有 + 無 使用技能的走法數

signed main()
{
    int n; cin >> n;
    vector< vector<int> > dp(n + 1, vector<int>(2, 0));
    dp[0][0] = dp[1][0] = 1; dp[2][0] = 2; // 起始條件
    for(int i=3; i<=n; ++i)
    {
        dp[i][0] = dp[i-1][0] + dp[i-1][1] + dp[i-2][0] + dp[i-2][1];
        dp[i][1] = dp[i-3][0];
    }
    cout << dp[n][0] + dp[n][1] << '\n';
}