// Assignment A12-1
// Name: 黃士育
// Student Number: 114502540
// Course 2025-CE1003A-資工1A

#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define FOR(x,n) for(int x=0; x<n; ++x)

signed main()
{
    fio; int n; cin >> n;
    vector< vector<int> > matrix(n, vector<int>(n));
    FOR(i,n) FOR(j,n) cin >> matrix[i][j];
    FOR(i,n) FOR(j,n) cout << matrix[j][i] << " \n"[j==n-1];    // 轉置可以 ij 相反直接輸出，每行以空格隔開並在最後換行
}