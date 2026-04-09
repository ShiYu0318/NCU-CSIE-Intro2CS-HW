// Assignment A13
// Name: 黃士育
// Student Number: 114502540
// Course 2025-CE1003A-資工1A

#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

const int md[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};    // 每月天數
const vector<string> wk = {"Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday"};   // 從四開始

signed main()
{
    fio; int T; cin >> T;
    while(T--)
    {
        int M, D; cin >> M >> D;
        int sum = D;
        for (int i = 0; i < M-1; ++i) sum += md[i];
        cout << wk[(sum - 1) % 7] << '\n';  // 天數 % 7 可查表看星期幾
    }
}