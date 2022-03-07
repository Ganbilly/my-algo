import sys
import heapq
input = sys.stdin.readline

n = int(input())
graph = [list(map(int, input().split())) for _ in range(n)]

for i in range(n):
    pq = []
    visited = [0] * n
    heapq.heappush(pq, i)
    while len(pq) != 0:
        tmp = heapq.heappop(pq)
        
        for j in range(n):
            if (graph[tmp][j] == 1) and (not visited[j]):
                graph[i][j] = 1
                heapq.heappush(pq, j)
                visited[j] = True
                

for i in range(n):
    for j in range(n):
        print(graph[i][j], end=' ')
    print()