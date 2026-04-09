// Assignment A08-2
// Name: 黃士育
// Student Number: 114502540
// Course 2025-CE1003A-資工1A

#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;++i)

const int N = 1e4+5;
bitset<N> np;   // 記錄非質數，初始全 0，不用 bool 用 bitset 空間優化

void pre(int n)
{   // 歐拉篩（線性）預先建好質數表
    vector<int> p;
    FOR(i,2,n)
    {
        if(!np[i]) p.emplace_back(i);
        for(int j : p) 
        {
            if(i * j > n) break;
            np[i * j] = 1;
            if(i % j == 0)  break;
        }
    }
}

signed main()
{
    fastio; // 快速 I/O
    int n; cin >> n;
    int a = 0, b = 0;
    np[1] = 1; pre(N);
    FOR(i,1,n+1)
    {   // 編號是質數或偶數紀錄次數和總和
        if(!(np[i] && (i & 1))) { ++a; b += i; }
    }
    cout << a << ' ' << b << '\n';
}