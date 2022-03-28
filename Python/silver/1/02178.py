import sys
import heapq
input = sys.stdin.readline

m, n = map(int, input().split())

l = [input().strip() for _ in range(m)] 
dr = [1, -1, 0, 0]
dc = [0, 0, 1, -1]
visited = [[100000] * n for _ in range(m)]
q = []
visited[0][0] = 1
heapq.heappush(q, [1, 0, 0])

while q:
    cnt, r, c = heapq.heappop(q)
    
    if (r == m - 1) and (c == n - 1):
        print(cnt)
        break
    
    for i in range(4):
        nr = r + dr[i]
        nc = c + dc[i]
        
        if (0 <= nr < m) and (0 <= nc < n) and (l[nr][nc] == '1') and (visited[nr][nc] > cnt + 1):
            visited[nr][nc] = cnt + 1
            heapq.heappush(q, [cnt+1, nr, nc])
    
    