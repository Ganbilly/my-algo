import sys

input = sys.stdin.readline

n, s = map(int, input().split())
arr = list(map(int, input().split()))

mindex = 0
length = 1000000
sum = 0

if s == 0:
    print(0)
    exit()

for i in range(n):
    sum += arr[i]
    if sum >= s:    
        while sum - arr[mindex] >= s:
            sum -= arr[mindex]
            mindex += 1
        
        length = min(length, i - mindex)
            
if length == 1000000:
    print(0)
else:
    print(length + 1)
    