import sys
from collections import deque
input = sys.stdin.readline
t = int(input())
for _ in range(t):
    p = input().strip()
    n = int(input())
    arr = input().strip('\n,[,]')
    l = []
    if n != 0:
        l = deque(arr.split(','))
    direction = True
    error = False

    for i in p:
        if i == 'R':
            direction = not direction
        elif (i == 'D') and (len(l) > 0):
            if direction:
                l.popleft()
            else:
                l.pop()

        elif (i == 'D') and (len(l) == 0):
            error = True
            break
    
    if error:
        print('error')
    else:
        if direction:
            print('[',end='')
            for i in range(len(l)):
                print(l[i],end='')
                if i != len(l) - 1:
                    print(',',end='')
            print(']')    
            
        else:
            print('[',end='')
            for i in range(len(l)-1, -1, -1):
                print(l[i],end='')
                if i != 0:
                    print(',',end='')
            print(']')  

