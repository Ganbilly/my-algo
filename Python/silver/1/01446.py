import sys
from collections import defaultdict
import heapq

input = sys.stdin.readline

n, d = map(int, input().split())

dist = [i for i in range(d + 1)]
l = defaultdict(list)

for _ in range(n):
    a, b, c = map(int, input().split())
    if b > d:
        continue
    l[a].append([c, b])
    
hq = []

for tmp in l[0]:
    heapq.heappush(hq, [tmp[0], tmp[1]])
    
heapq.heappush(hq, [1, 1])

while(hq):
    top = heapq.heappop(hq)
    
    if top[1] == d:
        print(top[0])
        exit()
    
    for tmp in l[top[1]]:
        if (dist[tmp[1]] > top[0] + tmp[0]):
            dist[tmp[1]] = top[0] + tmp[0]
            heapq.heappush(hq, [dist[tmp[1]], tmp[1]])
    heapq.heappush(hq, [top[0] + 1 , top[1] + 1])

i = d
while(i != 0):
    if dist[i] != i:
        break
    
print(dist[i] + (d - i))