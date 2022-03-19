import sys
input = sys.stdin.readline
n = input().strip()
cnt = 0

def sumnum(n):
    s = 0
    for i in n:
        s += int(i)
    return str(s)

while len(n)!=1:
    n = sumnum(n)
    cnt += 1
    

print(cnt)
if int(n) % 3 == 0:
    print('YES')
else:
    print('NO')