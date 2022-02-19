n = int(input())
con = 0
sum = 0
l = list(map(int, input().split()))
for i in range(n):
    if l[i] == 1:
        con += 1
        sum += con
    
    else :
        con = 0
print(sum)