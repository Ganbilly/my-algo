from re import L
import sys
input = sys.stdin.readline

maxk = 1299709
prime = []
arr = [True] * (maxk + 1)
arr[0], arr[1] = False, False

for i in range(2, int((maxk+1)**0.5)):
    for j in range(i*i, (maxk+1), i):
        arr[j] = False

for i in range(maxk+1):
    if arr[i]:
        prime.append(i)

t = int(input())

for _ in range(t):
    k = int(input())
    left = 0
    right = 100000
    mid = (left + right) // 2
    
    while True:
        if right == left + 1:
            if prime[left] == k:
                print(0)
            else:
                print(prime[right] - prime[left])
            break
            
        elif prime[mid] > k:
            right = mid
            mid = (left + right) // 2
        
        elif prime[mid] <= k:
            left = mid
            mid = (left + right) // 2
        