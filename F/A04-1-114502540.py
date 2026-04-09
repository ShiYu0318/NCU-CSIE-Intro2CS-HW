'''
Assignment A04-1
Name: 黃士育
Student Number: 114502540
Course 2025-CE1003A-資工1A
'''

# 枚舉每行利用 bucket 檢查有沒有重複元素，有的話就 early return 不合法情況
def Check_Rows(table):
    for row in table:
        bucket = []
        for c in row:
            if c != '.':
                if c in bucket:
                    return False
                bucket.append(c)
    return True

# 同樣邏輯，只是換成枚舉欄而已
def Check_Columns(table):
    for i in range(9):
        bucket = []
        for j in range(9):
            if table[j][i] != '.':
                if table[j][i] in bucket:
                    return False
                bucket.append(table[j][i])
    return True

# 枚舉 (i, j) 以 3 為間隔當作起始點，加上偏移量變成座標 (x, y)，再用同個邏輯檢查每個小方格
def Check_Subgrids(table):
    for i in range(0, 9, 3):
        for j in range(0, 9, 3):
            bucket = []
            for x in range(i, i+3):
                for y in range(j, j+3):
                    if table[x][y] != '.':
                        if table[x][y] in bucket:
                            return False
                        bucket.append(table[x][y])
    return True

table = [input() for _ in range(9)]
print("好耶" if Check_Rows(table) and Check_Columns(table) and Check_Subgrids(table) else "不好耶") 

'''
# 方法二：用一些語法糖和 set 簡化程式碼
# 要不重複元素代表用 set 去重之後數量會跟原本一樣

def Check_Rows(table):
    for row in table:
        row = [c for c in row if c != '.']
        if len(set(row)) != len(row): return False
    return True

def Check_Columns(table):
    for i in range(9):
        col = [table[j][i] for j in range(9) if table[j][i] != '.']
        if len(set(col)) != len(col): return False
    return True

def Check_Subgrids(table):
    for i in range(0, 9, 3):
        for j in range(0, 9, 3):
            sub = [table[x][y] for x in range(i, i+3) for y in range(j, j+3) if table[x][y] != '.']
            if len(set(sub)) != len(sub): return False
    return True

table = [input() for _ in range(9)]
print("好耶" if Check_Rows(table) and Check_Columns(table) and Check_Subgrids(table) else "不好耶") 
'''