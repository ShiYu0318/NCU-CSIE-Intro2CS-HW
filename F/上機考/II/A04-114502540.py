n = int(input())
mp = {}
for _ in range(n):
    name = input().split()
    idle = name[0]
    mp.setdefault(idle, set())
    for i in name[1:]:
        mp[idle].add(i)
mp = dict(sorted(mp.items()))
for idle, fans in mp.items():
    print(f"{idle} {len(fans)}")