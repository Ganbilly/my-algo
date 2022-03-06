import sys
import heapq
input = sys.stdin.readline

m, n = map(int, input().split())
t = [list(map(int, input().split())) for _ in range(n)]

pq = []

for i in range(n):
    for j in range(m):
        if t[i][j] == 1:
            heapq.heappush(pq, [t[i][j], i, j])

while len(pq) != 0:
    tv, ti, tj = heapq.heappop(pq)
    tv += 1
    
    if (ti < n - 1) and (t[ti + 1][tj] == 0):
        t[ti + 1][tj] = tv
        heapq.heappush(pq, [tv, ti + 1, tj])
    if (ti > 0) and (t[ti - 1][tj] == 0):
        t[ti - 1][tj] = tv
        heapq.heappush(pq, [tv, ti - 1, tj])
    if (tj < m - 1) and (t[ti][tj + 1] == 0):
        t[ti][tj + 1] = tv
        heapq.heappush(pq, [tv, ti, tj + 1])
    if (tj > 0) and (t[ti][tj - 1] == 0):
        t[ti][tj - 1] = tv
        heapq.heappush(pq, [tv, ti, tj - 1])

maxt = 0
for i in range(n):
    for j in range(m):
        if t[i][j] == 0:
            print(-1)
            exit()
        if t[i][j] > maxt:
            maxt = t[i][j]
            
print(maxt - 1)