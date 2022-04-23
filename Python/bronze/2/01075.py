import sys
input = sys.stdin.readline

n = int(input())
f = int(input())
n = n - (n % 100) 
i = (n // f) - 1
while True:
    if f * i >= n:
        tmp = f * i % 100
        break
    i += 1
    
if tmp < 10:
    print(0,end="")
print(tmp)