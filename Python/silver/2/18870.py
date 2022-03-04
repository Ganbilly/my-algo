import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
arr2 = []
_dict = {}

for i in range(n):
    arr2.append(arr[i])

arr2.sort()
count = 0
_dict[arr2[0]] =  0
for i in range(1, n):
    if arr2[i] != arr2[i - 1]:
        count += 1
        _dict[arr2[i]] = count
    
for i in range(n):
    print(_dict[arr[i]], end=' ')