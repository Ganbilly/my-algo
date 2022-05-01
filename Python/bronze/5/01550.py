import sys
input = sys.stdin.readline

n = input().strip()
n = '0x' + n
print(int(n, 16))