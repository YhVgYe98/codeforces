for i in range(int(input())):
    n = int(input())
    for y in range(2*n):
        for x in range(2*n):
            print('#' if ((y//2) + (x//2))%2 == 0 else '.', end="")
        print("")
