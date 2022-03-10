import sys
input = sys.stdin.readline

n, k = map(int, input().split())
coin = []
for i in range(n):
    coin.append(-int(input()))

coin.sort()
i = 0
count = 0
while i < len(coin):
    if k + coin[i] >= 0:
        k += coin[i]
        count += 1
    else:
        i += 1
        
print(count)