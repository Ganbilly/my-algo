import sys
input = sys.stdin.readline

l = int(input())
s = list(map(int, input().split()))
n = int(input())
s.append(0)
s.sort()
flag = False
for i in range(len(s) - 1):
    if (s[i] < n) and (s[i + 1] > n):
        left = s[i] + 1
        right = s[i + 1] - 1
        flag = True
        break

cnt = 0

if flag :
    cnt = right - left + ((n - left) * (right - n))

print(cnt)
