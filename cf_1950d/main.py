prime_list=[]
def only01(n:int):
    while(n):
        if(n%10 > 1):
            return False
        n = n//10
    return True

def primes(int n):
    all_num = [False]*n
    all_num[2] = True
    res = [2]
    for i in range(int(sqrt(n))):



