'''
Assignment A03-1
Name: 黃士育
Student Number: 114502540
Course 2025-CE1003A-資工1A
'''

secret = input()    # 輸入字串
ans = ""    # 最長回文子字串 預設為空字串

# 長度由大到小開始找且 >= 2，迴圈第三個參數用 -1 代表倒序
for size in range(len(secret), 1, -1):
    # 定義子字串起始點，range 裡放的是長度為 size 的子字串數量
    for st in range(len(secret) - size + 1):
        substr = secret[st : st+size] # 擷取子字串
        if substr == substr[::-1]:  # 字串切片 step = -1 代表倒序
            ans = substr
            break   # 因為長度由大到小來找 所以找到了就可以提早退出迴圈
    if ans: break

print(ans if ans else "No Palindrome")


"""
補充方法二: Manachar 演算法

上面的暴力法時間複雜度是 O(n^3)，但馬拉車是 O(n)
核心概念就是利用迴文字串的對稱性，搭配中心擴展法可以降到線性

def manachar(ss):
    s = "^#" + "#".join(ss) + "#$"   # 每個字符中間插入 '#' 保證長度為奇數，並在頭尾加上其他字符當作邊界
    p = [0] * len(s)    # 紀錄以每個元素為中心的最長擴展半徑
    c = r = mid = mxl = 0 # c: 目前擴展到最右邊的迴文子字串的中心點; r: 最右迴文子字串的右邊界; mid: 最長迴文子字串的中心點; mxl: 最長迴文子字串的半徑

    for i in range(1, len(s)-1):    # 枚舉每個元素當中心點，紀錄下最長擴展半徑
        l = 2 * c - i   # 對於 最右子字串的中心點 的對稱點
        if i < r: p[i] = min(p[l], r - i)   # 如果目前子字串中心點在最右子字串的右邊界範圍內，那目前子字串的半徑有兩種情況 取較小的當作初始值: 1. 繼承對於 最右子字串中心點 的對稱點 的半徑; 2. 從目前子字串中心點到目前最右子字串右邊界的距離
        while(s[i + 1 + p[i]] == s[i - 1 - p[i]]): p[i] += 1   # 從初始值開始嘗試擴展半徑
        if i + p[i] > r: c, r = i, i + p[i]     # 如果擴展到比目前最右子字串的右邊界還大就更新最右子字串的中心點與右邊界
        if p[i] > mxl: mid, mxl = i, p[i]   # 如果目前子字串半徑比最長子字串的大就更新中心點和半徑

    if mxl < 2: return ""   # 長度必須 >= 2

    st = (mid - mxl) // 2   # 轉換成原子字串
    return ss[st:st + mxl]

s = input()
ans = manachar(s)
print(ans if ans else "No Palindrome")
"""