import sys
input = sys.stdin.readline
a, b, c = map(int,input().split())
print((a * (10 ** c) // b) % 10)