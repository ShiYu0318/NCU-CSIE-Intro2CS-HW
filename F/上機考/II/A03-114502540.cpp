#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int t; cin >> t;
    for(int i=1;i<=t; ++i)
    {
        int a,b,c; cin >> a >> b >> c;
        if(a > c) swap(a,c);
        if(b > c) swap(b,c);
        if(a > b) swap(a,b);
        cout << "Case " << i << ": ";
        if(a + b <= c) cout << "Invalid\n";
        else if(a == b && b == c) cout << "Equilateral\n";
        else if(a == b || b == c || c == a) cout << "Isosceles\n";
        else if(a != b && b != c && c != a) cout << "Scalene\n";
    }
}