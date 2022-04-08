import sys
import heapq
input = sys.stdin.readline

n = int(input())
pq = []
for i in range(n):
    a, b, c = map(int, input().split())
    heapq.heappush(pq, [b, c])

l = []
tmp = heapq.heappop(pq)
heapq.heappush(l, [tmp[1], tmp[0]])
while pq:
    tmp = heapq.heappop(pq)
    
    if l[0][0] <= tmp[0]:
        heapq.heappop(l)
    heapq.heappush(l, [tmp[1], tmp[0]])
    
print(len(l))