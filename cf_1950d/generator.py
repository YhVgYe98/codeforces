divider_list=[]
for i in range(2):
    for ii in range(2):
        for iii in range(2):
            for iiii in range(2):
                for iiiii in range(2):
                    for iiiiii in range(2):
                        divider_list.append(100000*i+10000*ii+1000*iii+100*iiii+10*iiiii+1*iiiiii)

divider_list = divider_list[2:]

divider_set = set(divider_list)

def product01(n:int):
    while(not(n in divider_set)):
        can_div = False
        for i in divider_set:
            if n%i == 0:
                n = n/i
                can_div = True
                break
        if not can_div:
            return False
    return True
res = [1]
for i in range(3,500000):
    if product01(i):
        res.append(i)

print(res)
