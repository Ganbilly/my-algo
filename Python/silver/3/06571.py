import sys
input = sys.stdin.readline

fibo = [1, 2]
max = 10 ** 100
while fibo[-1] < max:
    fibo.append(fibo[-1] + fibo[-2])
    
while True:
    a, b = map(int, input().split())
    
    if (a == 0) and (b == 0):
        break
    
    for i in range(len(fibo)):
        if a <= fibo[i]:
            ai = i
            break;
    
    for i in range(len(fibo)):
        if b <= fibo[i]:
            bi = i
            break
    
    if b in fibo:
        print(bi - ai + 1)
    else:
        print(bi - ai)
        