import sys
input = sys.stdin.readline
n = int(input())
s = 0
i = 1
tmp = 0
while True:
    if n >= (10 ** i):
        s += ((10 ** i) - tmp) * i
        tmp = 10 ** i
        i += 1
    else:
        s += (n - tmp) * i - 1
        break

print(s + i)