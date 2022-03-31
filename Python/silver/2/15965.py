import sys
input = sys.stdin.readline
k = int(input())
max_num = k * 20
if max_num > 7500000:
    max_num = 7500000

l = [True] * (max_num + 1)
p = []
for i in range(2, int((max_num ** 0.5)) + 2):
    for j in range(i * i, max_num + 1, i):
        l[j] = False

i = 2
while len(p) <= k + 1:
    if l[i]:
        p.append(i)
    i += 1
       
print(p[k - 1])