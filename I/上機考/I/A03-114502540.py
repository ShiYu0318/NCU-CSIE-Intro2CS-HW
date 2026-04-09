'''
Mid-A03
黃士育-114502540
'''
dir = [[-1,0], [1,0], [0,-1], [0,1]]

def in_range(x,y,n): return (0 <= x and x < n and 0 <= y and y < n) 

n = int(input())
k = int(input())
tb = [[0] * n for _ in range(n)]

fire = []
for i in range(k):
    xy = list(map(int,input().split()))
    fire.append(xy)
    for d in dir:
        nx = xy[0] + d[0]
        ny = xy[1] + d[1]
        if in_range(nx, ny,n): tb[nx][ny] += 1

for i in range(n):
    for j in range(n):
        if [i,j] in fire: print("x", end="")
        else: print(tb[i][j], end="")
    print("")