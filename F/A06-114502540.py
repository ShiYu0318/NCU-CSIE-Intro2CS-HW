'''
Assignment A06
Name: 黃士育
Student Number: 114502540
Course 2025-CE1003A-資工1A
'''
legend_states = {'Yasuo' : {'HP' : 87, 'AD' : 87}, 'Yone' : {'HP' : 100, 'AD' : 90}, 
                'Teemo' : {'HP' : 80, 'AD' : 120}, 'Ahri' : {'HP' : 100, 'AD' : 110}, 
                'Galio' : {'HP' : 120, 'AD' : 90}, 'Bard' : {'HP' : 999, 'AD' : 999}}

# 把位移量建成表，用 index 查表可以直接得到新位置，讓 move() 不用寫很多判斷式
#               0:上    1:下    2:左    3:右   4:原地
move_vector = [[-1,0], [1,0], [0,-1], [0,1], [0,0]]

# 輸入測資並把兩個英雄資訊封裝成 map，避免產生一大堆全域變數的同時還可以在其他 function 中直接修改值不需額外用 global
map_data = [input().split() for _ in range(5)]
my_name = input()
my = {
    "name": my_name,
    'HP': legend_states[my_name]['HP'],
    'AD': legend_states[my_name]['AD'],
    'x': 0, 'y': 0
}

foe_name = [j for i in map_data for j in i if j not in [".", "#", "berries", "minion", "nexus"]][0]
foe = {
    "name": foe_name,
    'HP': legend_states[foe_name]['HP'],
    'AD': legend_states[foe_name]['AD'],
    "nexus_hp": 2
}

# 判斷是否可通行，超出邊界或遇到牆壁會原地停留
def passable(x, y): return ((0 <= x and x < 5 and 0 <= y and y < 5) and map_data[x][y] != "#")

def attack_minion():
    my["HP"] -= 10
    my["AD"] += 10
    map_data[my["x"]][my["y"]] = "."

def attack_foe():
    my["HP"] -= foe["AD"]
    foe["HP"] -= my["AD"]
    if foe["HP"] <= 0: map_data[my["x"]][my["y"]] = "."

def move(dir):
    # 若我方死亡或摧毀主堡 移動操作無效
    if my["HP"] <= 0 or foe["nexus_hp"] <= 0 : return
    # 依據方向取得位移量產生新位置並檢查是否可通行 
    new_x, new_y = my["x"] + move_vector[dir][0], my["y"] + move_vector[dir][1]
    if passable(new_x, new_y): my["x"], my["y"] = new_x, new_y
    # 判斷更新後的位置遇到的東西並做出相應動作
    it = map_data[my["x"]][my["y"]]
    if it == "minion": attack_minion()
    elif it == foe["name"]: attack_foe()
    elif it == "berries": my["HP"] += 20
    elif it == "nexus": foe["nexus_hp"] -= 1

# 印出地圖並覆蓋上我方位置 X，使用 .ljust(8) 排版
def check_map():
    for i in range(5):
        print("".join(('X' if (i == my["x"] and j == my["y"]) 
                        else map_data[i][j]).ljust(8) for j in range(5)))

while True: # 操作指令輸入
    cmd = int(input())
    if cmd == 6: break
    elif cmd == 5: check_map()
    else: move(cmd)

# 遊戲結束
if foe["nexus_hp"] <= 0: print("Victory")
elif my["HP"] <= 0: print("Defeat")
else:
    print("Defeat")
    check_map()