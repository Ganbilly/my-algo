import sys
input = sys.stdin.readline

t = int(input())

def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a%b)
    
for _ in range(t):
    a, b = map(int, input().split())
    if a > b:
        tmp = gcd(a, b)
    else:
        tmp = gcd(b, a)
    
    print(tmp * (a//tmp) * (b//tmp))