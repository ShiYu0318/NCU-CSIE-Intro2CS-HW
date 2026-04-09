// Assignment A11-1
// Name: 黃士育
// Student Number: 114502540
// Course 2025-CE1003A-資工1A

#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(0); cin.tie(0)
#define SZ(x) (int)(x).size()
#define itc(x) char('0' + x)    // int to char
#define cti(x) (x - '0')        // char to int

// 大整數加法函數
// 回傳：兩數相加的結果字串
string bigNumberAdd(string num1, string num2)
{
    // 請實作函數
    string num3;    // 相加結果字串
    num2 = string(SZ(num1) - SZ(num2), '0') + num2;  // 先把 num2 補上前綴 0 到與 num1 同長度
    int c = 0;  // 是否進位
    for(int i = SZ(num1)-1; i >= 0; --i)    // 從右到左加
    {
        int add = cti(num1[i]) + cti(num2[i]) + c;  // 轉成數字
        num3 = itc(add % 10) + num3;    // 取個位數串在結果前面
        c = add / 10;   // 紀錄進位
    }
    if(c) num3 = '1' + num3;    // 最前面的進位
    return num3;
}

// 比較兩個大整數字串的大小，並確保 num1 >= num2（如果 num1 < num2 則交換）
void compareAndSwap(string &num1, string &num2)
{
    // 請實作函數：先比長度，若長度一樣再比字典序
    if(SZ(num1) < SZ(num2) || (SZ(num1) == SZ(num2) && num1 < num2)) swap(num1, num2);
}

// 大整數減法函數
// 回傳：兩數相減的結果字串（差的絕對值）
string bigNumberSub(string num1, string num2)
{
    // 請實作函數
    string num3;
    num2 = string(SZ(num1) - SZ(num2), '0') + num2;  // 先把 num2 補上前綴 0 到與 num1 同長度
    for(int i=0; i < SZ(num1); ++i)
    {
        num3 += itc((10 - cti(num2[i]) + cti(num1[i])) % 10);   // 統一用借位後取個位數處理，不用分成直接減或要借位
        if(num1[i] < num2[i])   // 當要借位時才去往前處理
        {
            for(int j = SZ(num3)-2; j >= 0; --j)    // 從借位的地方往前處理，有可能會一直借，例如
            {
                num3[j] = itc((cti(num3[j]) + 10 - 1) % 10);    // 這樣寫不用另外處理不夠減的情況
                if(num3[j] != '9') break; // 如果遇到 0 要繼續往前借
            }
        }
    }
    int k; for(k = 0; k < SZ(num3)-1 && num3[k] == '0'; ++k);   // 消除前綴零 並保留 a - b = 0 的情況
    return num3.substr(k, SZ(num3) - k);
}

int main()
{
    fio;
    string a, b;
    cin >> a >> b;

    // 先比較並交換，確保 a >= b
    compareAndSwap(a, b);

    // 計算加法和減法
    string sum = bigNumberAdd(a, b);
    string diff = bigNumberSub(a, b);

    cout << "sum: " << sum << endl;
    cout << "diff: " << diff << endl;

    return 0;
}
