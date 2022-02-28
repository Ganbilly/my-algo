import sys
input = sys.stdin.readline

n, k = map(int, input().split())

obj = [list(map(int, input().split())) for _ in range(n)]
arr = [list([0] * (k + 1)) for _ in range(n + 1)]

for i in range(1, n + 1):
    for j in range(1, k + 1):
        if obj[i - 1][0] > j:
            arr[i][j] = arr[i - 1][j]
            
        else:
            arr[i][j] = max(arr[i - 1][j], arr[i - 1][j - obj[i - 1][0]] + obj[i - 1][1])
            
print(arr[n][k])