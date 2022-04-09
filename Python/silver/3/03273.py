import sys
input = sys.stdin.readline

n = int(input())
l = list(map(int, input().split()))
x = int(input())
i = 0 
j = n - 1
cnt = 0
l.sort()
while i != j:
    tmp = l[i] + l[j]
    if tmp == x:
        cnt += 1
        i += 1
    elif tmp > x:
        j -= 1
    elif tmp < x:
            i += 1
            
print(cnt)