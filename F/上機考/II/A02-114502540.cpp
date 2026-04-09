#include <bits/stdc++.h>
using namespace std;
#define int long long

int f(int n)
{
    int cnt = 1;
    while(n != 1)
    {
        if(n & 1) n = 3*n+1;
        else n >>= 1;
        ++cnt;
    }
    return cnt;
}

signed main()
{
    int a, b, aa, bb;
    while(cin >> a >> b)
    {
        aa = a; bb = b;
        if(a > b) swap(a, b);
        int mx = -1;
        for(int i=a; i<=b; ++i) mx = max(mx, f(i));
        cout << aa << " " << bb << " " << mx << '\n';
    }
}