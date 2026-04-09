#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, tmp;
    while (cin >> N && N)
    {
        int t = 1, d = 6, n = 2, s = 5, w = 3, e = 4;
        for(int i=0; i<N; ++i)
        {
            string op; cin >> op;
            if(op == "north") { tmp = t; t = s; s = d; d = n; n = tmp; }
            else if(op == "south") { tmp = t; t = n; n = d; d = s; s = tmp; }
            else if(op == "west") { tmp = t; t = e; e = d; d = w; w = tmp; }
            else { tmp = t; t = w; w = d; d = e; e = tmp; }
        }
        cout << t << '\n';
    }
}