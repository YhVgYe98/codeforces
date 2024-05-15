for i in range(int(input())):
    a, b, c = input().split()
    if a<b and b<c:
        print("STAIR")
    elif a<b and b>c:
        print("PEAK")
    else:
        print("NONE")
