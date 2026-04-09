'''
Mid-A05
黃士育-114502540
'''

# ['2\r\n', '\r\n', 'Juan Soto\r\n', 'juan soto\r\n', 'Fernando Tatis\r\n', 'Manny Machado\r\n', 'Fernando Tatis\r\n', 'Fernando Tatis\r\n', '\r\n', 'Jacob deGrom\r\n', 'Max Scherzer\r\n', 'Max Scherzer\r\n', 'Justin Verlander\r\n', 'Gerrit Cole\r\n', 'Justin Verlander\r\n', 'Justin Verlander\r\n', '\r\n']

import sys

data = sys.stdin.readlines()
t = int(data[0].strip())
p = 2

for i in range(t):
    mp = {}
    cnt = 0
    while p < len(data):
        name = data[p].strip()
        if name == "": break
        else:
            if name not in mp: mp[name] = 1
            else: mp[name] += 1
            cnt += 1
            p += 1
    p += 1

    key = []
    for j in mp: key.append(j)
    key.sort()
    for j in key: print(f"{j} {(mp[j] / cnt * 100):.4f}")
    if i != t-1: print()