#include <bits/stdc++.h>
using namespace std;

// O(n) 雙指針 Greedy

int main()
{
    int n; cin >> n;
    vector<int> v(n);
    for(auto &i:v) cin >> i;
    int mx = INT_MIN;
    for(int i=0, j=n-1; i<j;)
    {
        mx = max(mx, (j - i) * min(v[i],v[j]));
        if(v[i] < v[j]) ++i;
        else --j;
    }
    cout << mx << '\n';
}