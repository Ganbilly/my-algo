import heapq

n = int(input())
l = [int(input()) for _ in range(n)]

first = l[0] * -1
count = 0
tmp = 0
pq = []

if len(l) == 1:
    print(0)
    exit()

for i in range(1, len(l)):
    heapq.heappush(pq, -l[i])
    
while True:
    if first < pq[0] :
        break;
    heapq.heappush(pq, heapq.heappop(pq) + 1)
    first -= 1
    count += 1
        
print(count)
    
