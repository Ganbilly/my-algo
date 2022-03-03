from collections import defaultdict
import sys
import heapq

input = sys.stdin.readline
INF = 1000000007

v, e = map(int, input().split())
k = int(input())
k -= 1
visited = [False] * v
distarr = [INF] * v
distarr[k] = 0
pq = []
graph = defaultdict(list)

for i in range(e):
    a, b, c = map(int, input().split())
    graph[a - 1].append([c, b - 1])
    
heapq.heappush(pq, [0, k])

while len(pq) != 0:
    dist, node = heapq.heappop(pq)
    if visited[node]:
        continue
    visited[node] = True;
    for i in range(len(graph[node])):
        if node == graph[node][i][1]:
            continue
        if distarr[graph[node][i][1]] > dist + graph[node][i][0] :
            distarr[graph[node][i][1]] = dist + graph[node][i][0]
            heapq.heappush(pq, [distarr[graph[node][i][1]], graph[node][i][1]])
            
for i in range(v):
    print('INF' if distarr[i] == INF else distarr[i])