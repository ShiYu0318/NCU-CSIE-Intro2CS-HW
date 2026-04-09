'''
Assignment A05-1
Name: 黃士育
Student Number: 114502540
Course 2025-CE1003A-資工1A
'''
# 想法：對於每個勞動券，用 map 查有哪些可以湊成兌換值

nums = list(map(int, input().split(',')))   # 用 map 迭代把每個元素轉成 int
target = int(input())
vis = {}  # 採用逐一加入 visited 的方式而非預先建好 pos_map，保證找到的配對永遠 i < j，且符合題目要求的輸出順序不用額外排序

for j, num in enumerate(nums):  # enumerate 遍歷可以同時取得 index 和 value
    diff = target - num     # 差值
    if diff in vis:     # 可以配對
        for i in vis[diff]:
            print(f"{i},{j}")
    
    if num in vis:  # 加入 vis 以供後續配對
        vis[num].append(j)
    else:   # 沒 key 就丟進去，value 要是 list
        vis[num] = [j]