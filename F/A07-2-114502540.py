'''
Assignment A07-2
Name: 黃士育
Student Number: 114502540
Course 2025-CE1003A-資工1A
'''
while(1):   # 多組測資輸入
    n = int(input())
    if n == 0: break;
    courses_cnt = {}    # 每種課程組合次數
    for _ in range(n):
        courses = frozenset(input().split())    # 把程組合轉成 frozenset 才可以當 dict 的 key
        courses_cnt[courses] = courses_cnt.get(courses, 0) + 1
    print(sum(cnt for cnt in courses_cnt.values() if cnt == max(courses_cnt.values())))
# 題目說沒用 set 會扣 10 分，但沒說不能用其他的，不太確定用 frozenset + dict 算過嗎？