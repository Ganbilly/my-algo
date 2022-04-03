import sys
input = sys.stdin.readline
MOD = 1000000000
n = int(input())
dp = [0, 1]
if n == 0:
    print(0)
    print(0)
    exit()
    
for i in range(1, abs(n)):
    dp.append((dp[i] + dp[i - 1])%MOD)

if (n < 0) and (abs(n) % 2 == 0):
    print(-1)
else:
    print(1)
print(dp[abs(n)])