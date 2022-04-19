import sys
input = sys.stdin.readline
n = int(input())
arr = list(map(int, input().split()))
l = 0;
r = n - 1
m = l + 1
absmin = [10 ** 15, []]

arr.sort()

for l in range(n - 2):
    r = n - 1
    m = l + 1
    
    while m < r:
        tmp = arr[l] + arr[m] + arr[r]
        if abs(tmp) < absmin[0]:
            absmin[0] = abs(tmp)
            absmin[1] = [arr[l], arr[m], arr[r]]
        if tmp == 0:
            print(arr[l], arr[m], arr[r])
            exit()
        
        elif tmp > 0:
            r -= 1
        else:
            m += 1
                
for i in absmin[1]:
    print(i, end=' ') 