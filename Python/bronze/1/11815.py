import sys
input = sys.stdin.readline

n = int(input())
l = list(map(int, input().split()))

for i in l:
    left = 1
    right = i
    mid = (left + right) // 2
    
    while True:
        if mid ** 2 == i:
            print(1, end=' ')
            break
        elif mid ** 2 > i:
            right = mid - 1
            mid = (left + right) // 2
        elif mid ** 2 < i:
            left = mid + 1
            mid = (left + right) // 2
            
        if left > right:
            print(0, end=' ')
            break
    