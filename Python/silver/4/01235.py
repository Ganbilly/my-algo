import sys
input = sys.stdin.readline

n = int(input())
l = []
for i in range(n):
    l.append(input().strip())

for i in range(1,len(l[0]) + 1):
    s = set()
    for j in range(n):
        s.add(l[j][-i:])
    
    if(len(s) == len(l)):
        print(i)
        exit()
        