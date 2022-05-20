import sys
input = sys.stdin.readline

a, p = map(int, input().split())


def nextnum(num, p):
    result = 0
    while(num != 0):
        result += (num % 10) ** p
        num //= 10
    
    return result


d = {a : 1}
last = a
while(True):
    last = (nextnum(last, p))
    if last not in d.keys():
        d[last] = 1
    elif d[last] == 3:
        break
    else:
        d[last] += 1
        
cnt = 0 
for key, val in d.items():
    if val == 1:
        cnt += 1

print(cnt)