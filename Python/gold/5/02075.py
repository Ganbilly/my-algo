import sys
import heapq

input = sys.stdin.readline

n = int(input())
pq = []
for i in range(n):
    l = list(map(int, input().split()))
    
    if len(pq)==0:
        for i in l:
            heapq.heappush(pq, i)
            
    else:
        for i in l:
            if pq[0] < i:
                heapq.heappush(pq, i)
                heapq.heappop(pq)
                
print(pq[0])
