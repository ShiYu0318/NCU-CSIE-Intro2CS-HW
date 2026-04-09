// Assignment A09-2
// Name: 黃士育
// Student Number: 114502540
// Course 2025-CE1003A-資工1A

#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(0); cin.tie(0)
// #define int long long

const int scores[9] = {10, 20, -15, -25, 15, -5, -6, -20, 25};
const string grades = "FDCBAA";

signed main()
{
    fio;
    int N; cin >> N;
    int pass = 0, sum = 0, mx = -1, mi = 101, score, code;
    for(int i=0; i<N; ++i)
    {
        score = 50; 
        while(cin >> code && code) score = min(max(0, score + scores[code-1]), 100); // 持續輸出直到 code == 0 條件不成立退出 while，並用 min/max 限制 score 範圍 [0, 100]
        cout << "Student "<< i+1 << " Final: " << score << "\nGrade: " << grades[max(0, score - 50) / 10] << '\n'; // 轉成十位數用查表的方式對應等第
        sum += score; pass += (score >= 60);    // 加總分數最後用來算平均；計算及格人數，不及格人數直接用扣的就好
        mx = max(mx, score); mi = min(mi, score); // 更新分數極值
    }
    cout << "Students: " << N << "\nPassed: " << pass << "\nFailed: " << N - pass << "\nAverage: " << fixed << setprecision(2) << (double)sum / N << "\nHighest: " << mx << "\nLowest: " << mi << '\n';
}