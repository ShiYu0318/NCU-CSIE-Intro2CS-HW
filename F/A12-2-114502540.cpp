// Assignment A12-2
// Name: 黃士育
// Student Number: 114502540
// Course 2025-CE1003A-資工1A

// --------------------- 助教給的模板 -------------------------
/*
 * 說明：請實作 compareIntervals 與 mergeIntervals
 */
#include <iostream>
#include <vector>
#include <algorithm> // sort, max
using namespace std;

struct Interval {
    int start;
    int end;
};

// 實作排序規則
// 提示：若 a 的 start 較小回傳 true；若 start 相同則 end 較小回傳 true
bool compareIntervals(const Interval &a, const Interval &b) {
    // 請在此填寫程式碼
    if (a.start < b.start) return true;
    if (a.start == b.start && a.end < b.end) return true;
    return false;
}

// 接收未排序的 intervals，回傳合併後的結果
vector<Interval> mergeIntervals(vector<Interval>& intervals) {
    if (intervals.empty()) return {};

    // 1. 排序
    // 提示：使用 sort 函數，compareIntervals 作為排序規則
    sort(intervals.begin(), intervals.end(), compareIntervals);
    vector<Interval> result;
    
    // 2. 合併
    // 請在此填寫程式碼
    result.push_back(intervals[0]);
    for (int i=0; i < intervals.size(); ++i)
    {
        Interval &last = result.back();
        Interval &now = intervals[i];
        // 如果起始時間重疊到上一個時間 就更新結束時間
        if (now.start <= last.end) last.end = max(last.end, now.end);
        else result.push_back(now);
    }
    return result;
}

int main() {
    int n;
    if (cin >> n) {
        vector<Interval> intervals(n);
        for (int i = 0; i < n; i++) {
            cin >> intervals[i].start >> intervals[i].end;
        }

        vector<Interval> result = mergeIntervals(intervals);

        int totalDuration = 0;
        for (size_t i = 0; i < result.size(); i++) {
            cout << result[i].start << " " << result[i].end << endl;
            totalDuration += (result[i].end - result[i].start);
        }
        cout << "Total Duration: " << totalDuration << endl;
    }
    return 0;
}

// --------------------------- 自己的寫法 -------------------------------
// #include <bits/stdc++.h>
// using namespace std;
// #define fio ios_base::sync_with_stdio(0); cin.tie(0)
// #define int long long
// #define F first
// #define S second

// signed main()
// {
//     fio; int n; cin >> n;
//     vector< pair<int,int> > day(n);
//     for(auto &p : day) cin >> p.F >> p.S;
//     sort(day.begin(), day.end());
//     day.emplace_back(24, 24);
//     int l = day[0].F, r = day[0].S, sum = 0;
//     for(int i=1; i<=n; ++i)
//     {
//         if(day[i].F <= r) r = max(r, day[i].S);
//         else
//         {
//             cout << l << " " << r << '\n';
//             sum += r - l;
//             l = day[i].F;
//             r = day[i].S;
//         }
//     }
//     cout << "Total Duration: " << sum << '\n';
// }