'''
Assignment A02
Name: 黃士育
Student Number: 114502540
Course 2025-CE1003A-資工1A
'''

# 使用 input() 輸入一個字串，因為要做運算所以要先轉型別成整數 int，最後賦值給變數 N（名稱依照題目給定，並非無意義）
N = int(input())

# 根據題目的規則，有 4 種情況，使用條件判斷式來決定要輸出什麼，首先檢查 N 是否被 4 整除
if N % 4 == 0:
    # 其中要使用巢狀條件判斷式先檢查是否同時也被 5 整除，如果是就輸出 "LIGHTNING BOLT"，這是編號 3 的情況
    if N % 5 == 0:
        print("LIGHTNING BOLT")
    else:   # 否則只被 4 整除就輸出 "FIRE"，這是編號 1 的情況
        print("FIRE")
elif N % 5 == 0:    # 如果不被 4 整除才會到這個 elif，如果 N 被 5 整除就輸出 "LIGHTNING"，這是編號 2 的情況
    print("LIGHTNING")
else:   # 如果都不被 4 或 5 整除才會到這個 else，直接輸出 N，這是編號 4 的情況
    print(N)