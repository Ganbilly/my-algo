import sys
input = sys.stdin.readline

d = {}
for _ in range(28):
    d[int(input())] = 1
    
l = []
for i in range(1, 31):
    if i not in d.keys():
        l.append(i)
        
l.sort()
print(l[0])
print(l[1])