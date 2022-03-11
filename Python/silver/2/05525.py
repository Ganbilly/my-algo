# 50점 코드
# import sys
# input = sys.stdin.readline

# n = int(input())
# m = int(input())
# s = list(input())
# i = 0
# count = 0
# pn = ['I'] + (['O','I'] * n)
# while s[i] != '\n':
#     if (s[i] == 'I') and (i + len(pn) < m) and (s[i:i+len(pn)] == pn) :
#         count += 1
#     i += 1
    
# print(count)

# 100점 코드

import sys
input = sys.stdin.readline

n = int(input())
m = int(input())
s = list(input())
tmp = 0
count = 0
i = 0
while i < m:
    if (s[i - 1] == 'I') and (s[i] == 'O') and (s[i + 1] == 'I'):
        tmp += 1
        if tmp == n:
            tmp -= 1
            count += 1
        i += 1
    else:
        tmp = 0
    i += 1
    
print(count)