'''
Mid-A04
黃士育-114502540
'''
rt, rj, st, sj = input().split()
rt = int(rt)
rj = int(rj)
st = int(float(st) * 100)
sj = int(float(sj) * 100)

if (rt - 1) / st < (rj - 1) / sj: print('TAOYUAN')
elif (rt - 1) / st > (rj - 1) / sj: print('JAKARTA')
else: print('SAME')