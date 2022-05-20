a = input()
b = input()

d = {
    'I': 1,
    'V': 5,
    'X': 10,
    'L': 50,
    'C': 100,
    'D': 500,
    'M': 1000
}

def rtoi(str):
    result = 0
    i = 0
    while(i < len(str)):
        if ((i + 1 != len(str)) and (d[str[i]] < d[str[i + 1]])):
            result += d[str[i + 1]] - d[str[i]]
            i += 2
        else:
            result += d[str[i]]
            i += 1
    
    return result

def itor(n):
    s = ''
    l = [
        [1000, 'M'], [900, 'CM'],
        [500, 'D'], [400, 'CD'],
        [100, 'C'], [90, 'XC'],
        [50, 'L'], [40, 'XL'],
        [10, 'X'], [9, 'IX'],
        [5, 'V'], [4, 'IV'],
        [1, 'I']
    ]
    i = 0
    while(n != 0):
        while(i < len(l)):
            if n >= l[i][0]:
                s += l[i][1]
                n -= l[i][0]
                break
            elif n >= l[i + 1][0]:
                s += l[i + 1][1]
                n -= l[i + 1][0]
                break
            i += 2
    
    return s

inta = rtoi(a)
intb = rtoi(b)
result = inta + intb
print(result)
print(itor(result))
