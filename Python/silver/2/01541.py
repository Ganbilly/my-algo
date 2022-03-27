import sys
input = sys.stdin.readline

s = input().strip()

result = 0
tmp = ''
flag = True     # flag, True = plus, False = minus
for i in range(len(s)):
    if s[i] == '-':
        if flag:
            result += int(tmp)
            flag = False
        else:
            result -= int(tmp)
        
        tmp = ''
    elif s[i] == '+':
        if flag:
            result += int(tmp)
        else:
            result -= int(tmp)
        tmp = ''
    else:
        tmp += s[i]
if flag:
    result += int(tmp)
else:
    result -= int(tmp)        
print(result)