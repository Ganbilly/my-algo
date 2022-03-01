import sys
input = sys.stdin.readline
n = int(input())
p = [list(map(int, input().split())) for _ in range(n)]
p.append(p[0])
suma = 0
sumb = 0

for i in range(n):
    suma += p[i][0] * p[i + 1][1]
    sumb += p[i][1] * p[i + 1][0]
    
result = round(abs(suma - sumb) / 2, 1)
print(result)