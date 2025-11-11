for _ in range(int(input())):
    n = int(input())
    a = map(int, input().split(" "))

    a = sorted(a)

    yes = True
    for i in range(1,n,2):
        if i+1<n:
            if a[i] != a[i+1]:
                yes = False
                break
    print("Yes" if yes else "NO")