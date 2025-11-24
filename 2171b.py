def solution():
    n = int(input())
    a = list(map(int, input().split()))
    if a[0] == -1 and a[-1] == -1:
        a[0] = 0
        a[-1] = 0
    if a[0] == -1:
        a[0] = a[-1]
    if a[-1] == -1:
        a[-1] = a[0]
    for i in range(len(a)):
        if a[i] == -1:
            a[i] = 0
    print(abs(a[-1]-a[0]))
    print(' '.join(list(map(str,a))))





for _ in range(int(input())):
    solution()