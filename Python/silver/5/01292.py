import sys
input = sys.stdin.readline

a, b = map(int, input().split())
arr = []
sum = 0
i = 1
while True:
    for _ in range(i):
        arr.append(i)
    i += 1
    
    if(len(arr) > b):
        break

for j in range(a - 1, b):
    sum += arr[j]
    
print(sum)