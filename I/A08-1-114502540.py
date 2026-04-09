'''
Assignment A08-1
Name: 黃士育
Student Number: 114502540
Course 2025-CE1003A-資工1A
'''

def gen(s):
    I = ""  # 新結果
    cnt = 1 # 累積連續次數
    s += "#" # 結束字符
    for i in range(1, len(s)):
        if s[i-1] == s[i]: cnt += 1 
        else: # 中斷連續 添加進結果
            I += str(cnt) + s[i-1]
            cnt = 1
    return I

N = int(input())
I = input()
for _ in range(N):
    print(I)
    I = gen(I)  # 生成下一項