#include <bits/stdc++.h>
using namespace std;

// 費氏進位 Greedy

const int MN = 1e9;

int main()
{
    int N; cin >> N;
    vector<int> f{1,2};
    for(int i=2; f[i-1] < MN; ++i) f.emplace_back(f[i-1] + f[i-2]);
    while(N--)
    {
        int t; cin >> t; cout << t;
        string s;
        for(int i=f.size()-1, b=0; i>=0; --i)
        {
            if(t >= f[i])
            {
                t -= f[i];
                s += "1";
                b = 1;
            }
            else if(b) s += "0";
        }
        cout << " = " << s << " (fib)\n";
    }
}