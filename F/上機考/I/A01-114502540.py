'''
Mid-A01
黃士育-114502540
'''
def prime(n):
    for i in range(2,n):
        if i*i > n: break
        if n % i == 0: return False
    return True

n = int(input())
if not prime(n): print("RAMI")
else:
    rev = int(str(n)[::-1])
    if prime(rev) and n != rev: print("ASA")
    else: print("RORA")