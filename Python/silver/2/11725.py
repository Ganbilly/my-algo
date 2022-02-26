import sys

input = sys.stdin.readline

n = int(input())
arr = {}

# 입력 받은 값으로 연결 리스트 만들기
for i in range(n - 1):
    a, b = map(int, input().split())
    if a - 1 in arr:
        arr[a - 1].append(b - 1)
    else:
        arr[a - 1] = [b - 1]
    if b - 1 in arr:
        arr[b - 1].append(a - 1)
    else:
        arr[b - 1] = [a - 1]

# bfs 로 탐색

parents = [-1] * n
queue = [0]
parents[0] = 1
while len(queue):
    tmp = queue[0]
    del queue[0]
    if tmp in arr:
        for i in range(len(arr[tmp])):
            if parents[arr[tmp][i]] == -1:
                queue.append(arr[tmp][i])
                parents[arr[tmp][i]] = tmp
            
for i in range(1, n):
    print(parents[i] + 1)