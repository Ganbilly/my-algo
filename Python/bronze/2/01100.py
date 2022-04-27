import sys
input = sys.stdin.readline
board = [list(input().strip()) for _ in range(8)]
cnt = 0
for i in range(8):
    for j in range(8):
        if (i + j) % 2 == 1:
            continue
        if board[i][j] == 'F':
            cnt += 1
            
print(cnt)