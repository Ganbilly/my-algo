import sys
input = sys.stdin.readline

t = int(input())

for i in range(t):
    n = int(input())
    arr = [0] * n
    if n < 3:
        print(1)
        continue
    
    arr[0] = 1
    arr[1] = 1
    arr[2] = 1
    
    for i in range(3, n):
        arr[i] = arr[i - 2] + arr[i - 3]
    
    print(arr[n - 1])