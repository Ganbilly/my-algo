import sys
input = sys.stdin.readline

t = int(input())

for _t in range(t):
    n = int(input())
    sticker = [list(map(int, input().split())) for _ in range(2)]
    dp = [list([0] * n) for _ in range(2)]

    dp[0][0] = sticker[0][0]
    dp[1][0] = sticker[1][0]
    
    if n == 1:
        print(max(dp[0][0], dp[1][0]))
        continue
    
    
    for i in range(1, n):
        dp[0][i] = max(dp[1][i - 1] + sticker[0][i], dp[0][i - 1])
        dp[1][i] = max(dp[0][i - 1] + sticker[1][i], dp[1][i - 1])
    
    print(max(dp[0][n - 1], dp[1][n - 1]))
