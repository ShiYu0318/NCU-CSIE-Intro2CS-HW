'''
Assignment A05-2
Name: 黃士育
Student Number: 114502540
Course 2025-CE1003A-資工1A
'''

student_num = int(input())
sign_num = int(input())
sign = {}   # key: num, value: [time, ...]

for _ in range(sign_num):
    try:    # 例外處理
        num, time = map(int, input().split(','))
    except ValueError:  # 如果座號包含文字，在轉成 int 時會出錯
        print("錯誤: 座號不可包含文字")
        continue

    if time < 0:
        print("錯誤: 簽到時間不可為負數")
        continue

    if num in sign: # 把簽到的時間都加入這個座號
        sign[num].append(time)
    else:
        sign[num] = [time]

no_come = []
delay = []
repeat = []

for i in range(1, student_num+1):
    if i not in sign:   # 沒來
        no_come.append(i)
    elif len(sign[i]) > 1:  # 代簽 有重複
        repeat.append(i)
    elif sign[i][0] > 30:   # 遲到 且只簽一次
        delay.append(i)

print("沒來的學生:" + ",".join(map(str, no_come)))
print("遲到的學生:" + ",".join(map(str, delay)))
print("有代簽的學生:" + ",".join(map(str, repeat)))