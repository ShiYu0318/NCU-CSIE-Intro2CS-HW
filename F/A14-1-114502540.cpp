// Assignment A14-1
// Name: 黃士育
// Student Number: 114502540
// Course 2025-CE1003A-資工1A

#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

int A(int m, int n)
{   // 依據題目規則分開回傳 或繼續遞迴
    if(m == 0) return n+1;
    else if(m > 0 && n == 0) return A(m-1, 1);
    else if(m > 0 && n > 0) return A(m-1, A(m, n-1));
}

signed main()
{
    fio; int m, n; cin >> m >> n;
    cout << A(m, n) << '\n';    // 呼叫遞迴函數
}