import sys
input = sys.stdin.readline

month = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
day = ['SUN', 'MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT']
x, y = map(int, input().split())

cnt = 0
i = 1
while x != i:
    cnt += month[i]
    i += 1
cnt += y

print(day[cnt%7])