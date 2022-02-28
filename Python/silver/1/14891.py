import sys
from collections import deque


def spin(gn, direction):
    visited[gn] = 1
    if (gn < 3) and (visited[gn + 1] == 0) and (gear[gn][2] != gear[gn + 1][-2]):
        spin(gn + 1, direction * -1)
    if (gn > 0) and (visited[gn - 1] == 0) and (gear[gn][-2] != gear[gn - 1][2]):
        spin(gn - 1, direction * -1)
    gear[gn].rotate(direction)


input = sys.stdin.readline
gear = [deque(input().strip()) for _ in range(4)]
k = int(input())
spins = [list(map(int, input().split())) for _ in range(k)]
visited = []

for i in range(k):
    visited = [0] * 4
    spin(spins[i][0] - 1, spins[i][1])
    
score = 0

for i in range(4):
    score += int(gear[i][0]) * (1 << i)
    
print(score)