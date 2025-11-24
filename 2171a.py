def solution():
    n = int(input())
    res = 0
    i = 0
    while(i*2<=n):
        if(n-2*i)%4==0:
            res += 1
        i += 1
    print(res)





for _ in range(int(input())):
    solution()