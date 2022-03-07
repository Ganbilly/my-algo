import sys
input = sys.stdin.readline

board = [list(input()) for _ in range(9)]
zero = []

for i in range(9):
    for j in range(9):
        if board[i][j] == '0':
            zero.append([i, j])

            
def printboard():
    global board
    
    for i in range(9):
        for j in range(9):
            print(board[i][j], end='')
        print()


def findnum(row, col):
    global board
    d = [0] + [i + 1 for i in range(9)]
    tmp1 = (row//3)*3
    tmp2 = (col//3)*3
    
    for i in range(9):
        d[int(board[row][i])] = 0
        d[int(board[i][col])] = 0
        
    for i in range(3):
        for j in range(3):
            d[int(board[tmp1 + i][tmp2 + j])] = 0

    return [str(i) for i in d if i != 0]
    
def fillboard(cnt):
    global board, zero
    
    if cnt == len(zero):
        printboard()
        exit()
        
    row, col = zero[cnt]
    d = findnum(row, col)
    
    for i in d:
        board[row][col] = str(i)
        fillboard(cnt + 1)
    board[row][col] = '0'
    
    
fillboard(0)