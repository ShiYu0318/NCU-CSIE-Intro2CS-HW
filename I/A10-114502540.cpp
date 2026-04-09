// Assignment A10
// Name: 黃士育
// Student Number: 114502540
// Course 2025-CE1003A-資工1A

#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(0); cin.tie(0)

signed main()
{
    fio;
    double K, LR, w, b, L, C, x, y, N, sx, sy, sxy, sxx, syy;
    cin >> K >> LR >> w >> b >> L >> C;
    N = sx = sy = sxy = sxx = syy = 0;

    // 讀入資料同時加總
    while(cin >> x >> y && !(x == -1 && y == -1))
    {   
        ++N;
        sx += x;
        sy += y;
        sxy += x * y;
        sxx += x * x;
        syy += y * y;
    }

    // N=0 的情況
    if(!N) { cout << fixed << setprecision(2) << 0.0 << '\n' << w << '\n' << b << '\n'; return 0; }
    
    double best_loss = DBL_MAX, pre_loss, best_w = w, best_b = b;
    for(int i=0; i<K; ++i)
    {
        double MSE = (syy - 2*w*sxy - 2*b*sy + w*w*sxx + 2*w*b*sx + N*b*b) / N;
        double L2_p = L * (w*w + b*b);
        double loss = MSE + L2_p;
        
        // D. 梯度
        double grad_w = (-2*sxy + 2*w*sxx + 2*b*sx) / N + 2*L*w;
        double grad_b = (-2*sy + 2*w*sx + 2*b*N) / N + 2*L*b;
        
        // E. 追蹤最佳解
        if(loss < best_loss)
        {
            best_loss = loss;
            best_w = w;
            best_b = b;
        }
        
        // F. 自適應學習率
        if(i)   // 第 0 次不用更新
        {
            if(loss > pre_loss) LR *= 0.5;
            else LR *= 1.05;
        }
        pre_loss = loss;
        
        // G. 梯度裁剪
        grad_w = max(min(grad_w, C), -C);
        grad_b = max(min(grad_b, C), -C);
        
        // H. 更新權重
        w = w - LR * grad_w;
        b = b - LR * grad_b;
    }
    cout << fixed << setprecision(2) << best_loss << '\n' << best_w << '\n' << best_b << "\n\n";
}