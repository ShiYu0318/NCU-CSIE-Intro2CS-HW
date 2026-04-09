#include <bits/stdc++.h>
using namespace std;

// O(n^2) 會過 助教測資出弱了

int main()
{
    int n; cin >> n;
    vector<int> v(n);
    for(auto &i:v) cin >> i;
    int mx = INT_MIN;
    for(int i=0;i<n-1;++i)
        for(int j=i+1;j<n;++j)
            mx = max(mx, (j - i) * min(v[i],v[j]));
    cout << mx << '\n';
}