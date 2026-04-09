'''
Assignment A09-1
Name: 黃士育
Student Number: 114502540
Course 2025-CE1003A-資工1A
'''
def check(n, matrix):
    for i in range(n):
        for j in range(n):
            # 以中心點為對稱 (n-1-i, n-1-j) 若不同則 early return
            if matrix[i][j] != matrix[n-1-i][n-1-j]: return False
    return True

T = int(input())
for i in range(T):
    n = int(input().split()[2])
    matrix = [input().split() for _ in range(n)] # 讀入矩陣
    print(f'Test #{i+1}: {"S" if check(n, matrix) else "Non-s"}ymmetric.')  # 針對兩種不同處輸出


'''
法二：攤平成一維，變成判斷回文
def check(matrix):
    flat = [x for row in matrix for x in row]
    return flat == flat[::-1]
'''