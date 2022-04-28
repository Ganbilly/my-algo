import sys
input = sys.stdin.readline

n = int(input())
m = [list(map(int, input().split())) for _ in range(n)]
visited = [[False] * n for _ in range(n)]
def dfs(i, j):
    global n
    visited[i][j] = True
    if m[i][j] == -1:
        print("HaruHaru")
        exit()    

    if (i + m[i][j] < n) and (visited[i + m[i][j]][j] == False):
        dfs(i + m[i][j], j)
    if (j + m[i][j] < n) and (visited[i][j + m[i][j]] == False):
        dfs(i, j + m[i][j])
        
dfs(0, 0)
print('Hing')