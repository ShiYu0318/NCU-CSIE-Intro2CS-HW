wk = ["Thursday","Friday","Saturday","Sunday","Monday","Tuesday","Wednesday"]
md = [31,28,31,30,31,30,31,31,30,31,30,31]
for _ in range(int(input())):
    M,D = map(int,input().split())
    print(wk[(sum(md[:M-1])+D-1)%7])