import sys
import heapq
input = sys.stdin.readline

n = int(input())
count = 0
h1 = [list(map(int, input().split())) for _ in range(n)]
h2 = []  

heapq.heapify(h1)
tmp = heapq.heappop(h1)
heapq.heappush(h2, [tmp[1], tmp[0]])

while len(h1) != 0:
    tmp = heapq.heappop(h1)
    
    while (len(h2) > 0) and (tmp[0] >= h2[0][0]):
        heapq.heappop(h2)
    
    heapq.heappush(h2, [tmp[1], tmp[0]])
    count = max(count, len(h2))        

print(count)