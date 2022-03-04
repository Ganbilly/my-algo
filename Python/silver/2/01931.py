import sys
input = sys.stdin.readline

n = int(input())
queue = []
for i in range(n):
    a, b = map(int, input().split())
    queue.append([b, a])
    
queue = sorted(queue, key = lambda x : (x[0], x[1]))

count = 1
end = queue[0][0]

for i in range(1, n):
    if end <= queue[i][1]:
        count += 1
        end = queue[i][0]
    
print(count)