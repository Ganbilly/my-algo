import sys
import heapq
input = sys.stdin.readline

hq = []

n = int(input())
for _ in range(n):
    x = int(input())
    if x == 0:
        if len(hq) != 0:
            tmp = heapq.heappop(hq)
            print(tmp[1])
        else:
            print(0)
    else:
        heapq.heappush(hq, [abs(x), x])
        
