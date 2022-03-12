import sys
input = sys.stdin.readline

r, c = map(int, input().split())
board = [list(input()) for _ in range(r)]
cnt = 0
step = {chr(i) : 0 for i in range(65,91)}

def dfs(i, j, ccnt):
    global cnt
    ccnt += 1

    if ccnt > cnt:
        cnt = ccnt
    
    if cnt == 26:
        print(cnt)
        exit()
            
    if (i > 0) and (step[board[i - 1][j]] == 0):
        step[board[i - 1][j]] = 1
        dfs(i - 1, j, ccnt)
        step[board[i - 1][j]] = 0
    if (i < r - 1) and (step[board[i + 1][j]] == 0):
        step[board[i + 1][j]] = 1
        dfs(i + 1, j, ccnt)
        step[board[i + 1][j]] = 0
    if (j > 0) and (step[board[i][j - 1]] == 0):
        step[board[i][j - 1]] = 1
        dfs(i, j - 1, ccnt)
        step[board[i][j - 1]] = 0
    if (j < c - 1) and (step[board[i][j + 1]] ==0):
        step[board[i][j + 1]] = 1   
        dfs(i, j + 1, ccnt)
        step[board[i][j + 1]] = 0   

step[board[0][0]] = 1
dfs(0, 0, 0)

print(cnt)
