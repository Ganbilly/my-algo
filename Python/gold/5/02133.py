import sys
input = sys.stdin.readline

n = int(input())

if n % 2 == 1:
    print(0)

else:
    dp = [0] * 31
    
    dp[2] = 3
    dp[4] = 11
    
    for i in range(6, n + 1, 2):
        dp[i] = (dp[i - 2] * 3) + (sum(dp[:i-2]) * 2) + 2
    
    print(dp[n])