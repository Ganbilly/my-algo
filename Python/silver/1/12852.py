n = int(input())
ans = [0] * 1000001

ans[1] = [0, [1]]
ans[2] = [1, [1, 2]]
ans[3] = [1, [1, 3]]
for i in range(4, n + 1):
    arr = [0]
    if i % 3 == 0:
        arr.append(ans[i // 3])
    if i % 2 == 0:
        arr.append(ans[i // 2])
    arr[0] = ans[i - 1]
    tmp = min(arr)
    ans[i] = [tmp[0] + 1, tmp[1] + [i]]
    
print(ans[n][0])
for i in range(len(ans[n][1])- 1, -1, -1):
    print(ans[n][1][i], end=" ")