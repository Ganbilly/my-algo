import sys
input = sys.stdin.readline

s = input().strip()
result = []
num = ['0','1','2','3','4','5','6','7','8','9']
snum = ['zero','one','two','three','four','five','six','seven','eight','nine']
i = 0
while i < len(s):
    if s[i] in num:
        result.append(s[i])
        i += 1
    else:
        tmp = []
        j = i
        while (j < len(s)) and (s[j] not in num):
            tmp.append(s[j])
            j += 1
        i = j
        
        tmp = ''.join(tmp)
        j = 0
        while tmp:
            if tmp.startswith(snum[j]):
                result.append(num[j])
                tmp = tmp[len(snum[j]):]
                j = 0
                continue
            j += 1
            
        
print(int(''.join(result)))