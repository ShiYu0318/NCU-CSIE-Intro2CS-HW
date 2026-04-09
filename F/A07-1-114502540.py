'''
Assignment A07-1
Name: 黃士育
Student Number: 114502540
Course 2025-CE1003A-資工1A
'''
def sort_groups(groups):    # 依照題目的規則自定義排序
    for group, members in groups.items():
        # sorted 可以用參數 key 指定排列方式，這裡用匿名函式 lambda 先依出現次數由多到少排列，再依名稱字典序排
        groups[group] = dict(sorted(members.items(), key = lambda it: (-it[1] , it[0])))
    return dict(sorted(groups.items(), key = lambda it: it[0]))  # 用同樣方法依照成員數量由多到少排

n = int(input())
groups = {}     # {"gruop_name.lower()" : {"member" : times, ...}, ...}
gruop_first = {}    # {"gruop_name.lower()" : gruop_name}

for _ in range(n):
    data = input().split()
    group = data[0].lower() # 團名固定以全小寫辨別
    groups.setdefault(group, {})    # 利用 setdefault 可以將沒出現過的團設為空 dict
    gruop_first.setdefault(group, data[0])  # 用同樣方法記錄第一次出現的團名
    for member in data[1:]:
        groups[group][member] = groups[group].get(member, 0) + 1    # 每個出現成員次數 + 1，利用 get 可以在成員沒出現過時預設為 0

groups = sort_groups(groups)

for group, members in groups.items():
    print(gruop_first[group], len(members))
    print("Members:")   # 公開測資要改成員名字首字母大寫其餘小寫，用 .capitalize()
    print(",".join(f"{member.capitalize()}({times})" for member,times in members.items()))