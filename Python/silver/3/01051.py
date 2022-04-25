import sys
input = sys.stdin.readline

n, m = map(int, input().split())
maxl = min(n, m)
l = [input().strip() for _ in range(n)]

def issame(a, b, c, d):
    if (a == b) and ( b == c ) and ( c == d):
        return True
    return False

for answer in range(maxl, 0, -1):
    for i in range(n):
        for j in range(m):
            if (j + answer - 1 >= m):
                break      
            
            if issame(l[i][j], l[i + answer - 1][j], l[i][j + answer - 1], l[i + answer - 1][j + answer - 1]):
                print(answer * answer)
                exit()
             
        if (i + answer >= n):
            breakW