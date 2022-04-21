import sys
input = sys.stdin.readline

n = int('0b'+ input().strip(), 2)
print(str(bin(n * 17))[2:])
