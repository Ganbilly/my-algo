def mulmat(a, b):
    result = [[0, 0], [0, 0]]
    result[0][0] = (a[0][0] * b[0][0]) + (a[0][1] * b[1][0])
    result[0][1] = (a[0][0] * b[0][1]) + (a[0][1] * b[1][1])
    result[1][0] = (a[1][0] * b[0][0]) + (a[1][1] * b[1][0])
    result[1][1] = (a[1][0] * b[0][1]) + (a[1][1] * b[1][1])
    
    return result

def fibo(n):
    a = [[1, 1], [1, 0]]
    
    if n == 1:
        return a;
    result = fibo(n//2)
    result = mulmat(result, result)
    if n % 2:
        result = mulmat(result, a)
    
    return result
    
n = int(input())
a = fibo(n)
print(a[1][1], a[0][1])

