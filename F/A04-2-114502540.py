'''
Assignment A04-2
Name: 黃士育
Student Number: 114502540
Course 2025-CE1003A-資工1A
'''

def Count_Words(data):
    return len(data)

# 先找最大值 再把符合最大值的單字包成 tuple 後變成 list 回傳
def Find_Longest(data):
    max_len = max(len(word) for word in data)
    return [(word, len(word)) for word in data if len(word) == max_len]

# 相同邏輯，只是改成最小值
def Find_Shortest(data):
    min_len = min(len(word) for word in data)
    return [(word, len(word)) for word in data if len(word) == min_len]

# 讀檔
# with open("-HW/dictionary.txt", "r", encoding="utf-8") as f:
#     data = f.read().split(',')

data = input().split(',')
print(f"總共有{Count_Words(data)}個單字\n最長的單字有:\n{Find_Longest(data)}\n最短的單字有:\n{Find_Shortest(data)}")