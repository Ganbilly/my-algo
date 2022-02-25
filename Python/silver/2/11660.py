import sys
input = sys.stdin.readline

n, m = map(int, input().split())

arr = []
ans = []
for i in range(n):
    arr.append(list(map(int, input().split())))

for i in range(1, n):
    arr[i][0] = arr[i - 1][0] + arr[i][0]
    arr[0][i] = arr[0][i - 1] + arr[0][i]

for i in range(1, n):
    for j in range(1, n):
        arr[i][j] = arr[i][j] + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1]

for k in range(m):
    x1, y1, x2, y2 = map(int, input().split())
    cnt = 0
    tmp = arr[x2 - 1][y2 - 1]
    if x1 != 1:
        tmp -= arr[x1 - 2][y2 - 1]
        cnt +=1
    if y1 != 1:
        tmp -= arr[x2 - 1][y1 - 2]
        cnt +=1
    if cnt == 2:
        tmp += arr[x1 - 2][y1 - 2]
    ans.append(tmp)
    
for i in ans:    
    print(i)


