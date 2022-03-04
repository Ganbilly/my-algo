import sys
input = sys.stdin.readline
n = int(input())
paper = [list(map(int, input().split())) for _ in range(n)]
wc = 0
bc = 0

def cut(startx, starty, n):
    global wc
    global bc
    color = paper[startx][starty]
    flag = False
    for i in range(startx, startx + n):
        for j in range(starty, starty + n):
            if color!= paper[i][j]:
                flag = True
                break
    
    if flag:
        cut(startx, starty, n//2)
        cut(startx + (n//2), starty, n//2)
        cut(startx, starty + (n//2), n//2)
        cut(startx + (n//2), starty + (n//2), n//2)
    else:
        if color == 0:
            wc += 1
        else:
            bc += 1

    
cut(0, 0, n)

print(wc)
print(bc)