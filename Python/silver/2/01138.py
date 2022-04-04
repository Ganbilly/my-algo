import sys
input = sys.stdin.readline

n = int(input())
l = list(map(int, input().split()))
result = [0] * n
for i in range(n):
    a = l[i]
    cnt = 0
    for j in range(n):
        if a == cnt and result[j] == 0:
            result[j] = i + 1
            break
        elif result[j] == 0:
            cnt += 1
    
print(*result)