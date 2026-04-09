'''
Assignment A01
Name: 黃士育
Student Number: 114502540
Course 2025-CE1003A-資工1A
'''

# 使用 input() 讀入整行字串，然後用 .split(",") 以 , 字符切分字串，變成有很多個子字串的 list，最後賦值給 data 這個變數
data = input().split(",")

# 讀取第二行的是否有獵人執照的布林值（因為沒有大小寫問題，所以直接以字串輸入不用特別轉成 bool）
license = input()

# 使用 f-string 的方式輸出，裡面放題目規定的格式，其中使用 \n 這個正則表達式代表換行，並且 {} 裡面可以嵌入變數，因為 data 已經被切分成由多個子字串組成的 list，所以可以直接用 [] 放 index 直接讀取，最後因為最後因為年齡身高要無條件捨去，所以要先把有可能帶有小數點的字串先強制轉型別成浮點數 float 再轉成整數 int 即可
print(f"姓名: {data[0]}\n年齡: {int(float(data[1]))}\n身高: {int(float(data[2]))}\n獵人執照: {license}")