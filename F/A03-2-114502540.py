'''
Assignment A03-2
Name: 黃士育
Student Number: 114502540
Course 2025-CE1003A-資工1A
'''

n = int(input())
data = input().split()
ans = 0

# Bubble Sort 因為每次遍歷都會浮出一個確定排序的數字，所以外層迴圈是控制次數
for i in range(n):
    # 內層迴圈從 i 開始往後遍歷
    for j in range(n-1-i):
        # 如果順序不對會兩兩交換
        if data[j] > data[j+1]:
            data[j], data[j+1] = data[j+1], data[j]
            ans += 1

print(" ".join(data) + f"\nswaps={ans}")


"""
補充方法二: Merge Sort
這題其實是逆序數對，用分治可以把時間複雜度從 O(n^2) 降到 O(n log n)

n = int(input())
data = input().split()

# 核心概念是把資料不斷切成左右兩半遞迴下去，在合併的過程中比較左右兩邊大小依照順序排好
def msort(arr):
    if len(arr) <= 1:
        return arr, 0
    mid = len(arr) // 2
    l, inv_l = msort(arr[:mid])
    r, inv_r = msort(arr[mid:])
    merged, inv_cnt = merge(l, r)
    return merged, inv_l + inv_r + inv_cnt

# 因為合併時左右部分都已經排好了，所以只要遇到 l[i] > r[j] 就可以直接 O(1) 算出某個元素後面有幾個元素比他小
def merge(l, r):
    merged = []
    i = j = 0
    inv_cnt = 0
    while i < len(l) and j < len(r):
        if l[i] > r[j]:
            merged.append(r[j])
            j += 1
            inv_cnt += len(l) - i  # 逆序數對
        else:
            merged.append(l[i])
            i += 1
    merged += l[i:] + r[j:]
    return merged, inv_cnt

data, ans = msort(data)
print(" ".join(data) + f"\nswaps={ans}")
"""