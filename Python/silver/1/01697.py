from heapq import heappop, heappush

n, k = map(int, input().split())

arr = [[0, n]]
tmp = []
visited = [False] * (max(n, k) * 2 + 1)
while True:
    tmp = heappop(arr)
    if (visited[tmp[1]]):
        continue
    visited[tmp[1]] = True
    if tmp[1] == k :
        break;
    
    tmp[0] += 1
    if (tmp[1] * 2 <= k * 2) and (not visited[tmp[1] * 2]):
        heappush(arr, [tmp[0], tmp[1] * 2])
    if (tmp[1] - 1 >= 0) and (not visited[tmp[1] - 1]):
        heappush(arr, [tmp[0], tmp[1] - 1])
    if (tmp[1] + 1 <= k * 2) and (not visited[tmp[1] + 1]):
        heappush(arr, [tmp[0], tmp[1] + 1])
    
        
print(tmp[0])