import sys
input = sys.stdin.readline
n = int(input())
sol = list(map(int, input().split()))
ans = []

for i in range(n - 1):
    a = sol[i]
    lower = i + 1
    upper = n - 1
    mid = (lower + upper) // 2
    
    while True:
        b = sol[mid]
        if upper - lower <= 1:
            ans.append(min([abs(a + sol[lower]), a, sol[lower]], [abs(a + sol[upper]), a, sol[upper]]))
            break
        elif a + b == 0:
            print(a, b)
            exit()
        elif a + b > 0:
            upper = mid
            mid = (lower + upper) // 2
        elif a + b < 0:
            lower = mid
            mid = (lower + upper) // 2
            
answer = min(ans)
print(answer[1], answer[2])