n = int(input())
arr = []
arr.append(0)
arr.append(1)
arr.append(2)

for i in range(3, n + 1):
    arr.append((arr[i - 1] + arr[i - 2]) % 10007) 
    
print(arr[n])