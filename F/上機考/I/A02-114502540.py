'''
Mid-A02
黃士育-114502540
'''
m = int(input())
q = []
p = 0
for i in range(100): q.append(i)
for i in range(99):
    for j in range(m-1):
        q.append(q[p])
        p += 1
    p += 1
print(q[p])