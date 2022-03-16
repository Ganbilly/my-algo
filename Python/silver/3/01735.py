import sys
input = sys.stdin.readline

a, b = map(int, input().split())
c, d = map(int, input().split())

a = a * d + c * b
b = b * d

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

if a > b:
    tmp = gcd(a, b)
else :
    tmp = gcd(b, a)
    
a//=tmp
b//=tmp

print(a, b)