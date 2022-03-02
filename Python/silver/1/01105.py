l , r = map(int, input().split())
l , r = str(l), str(r)
l = '0' * (len(r) - len(l)) + l
flag = True
count = 0

for i in range(len(l)):
    if (l[i] == r[i]):
        if (l[i] == '8') and (flag):
            count +=1
    else:
        flag = False
        
print(count)