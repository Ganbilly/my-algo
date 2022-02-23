a , b = map(int, input().split())

arr = [[a, 0]]
ans = []

while len(arr) != 0 :
    tmp = arr[0]
    del arr[0]
    if tmp[0] == b:
        ans.append(tmp[1] + 1)
    elif tmp[0] < b:
        arr.append([tmp[0] * 2, tmp[1] + 1])
        arr.append([tmp[0] * 10 + 1, tmp[1] + 1])

if len(ans) == 0:
    print(-1)
    exit()

ans.sort()
print(ans[0])
