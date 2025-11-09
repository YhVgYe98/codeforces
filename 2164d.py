# for _ in range(int(input())):
#     m, n = map(int, input().split())
#     s = list(input())
#     t = list(input())
#     path = []
#     step = 0
    
#     dist = [-1]*m
#     ptr = m-1 # 尾端符合条件的映射的位置
#     for i in reversed(range(m)):
#         ptr = min(ptr, i)
#         for j in reversed(range(ptr+1)):
#             if t[i] == s[j]:
#                 dist[i] = i-j
#                 ptr = j
#                 break
#         if dist[i] == -1 or dist[i]>n:
#             dist[i] == -1
#             break
    
#     if dist[0] == -1:
#         print("-1")
#         continue
    
#     step = max(dist)
#     path = [s.copy() for _ in range(step)]
#     for ind, dist_i in enumerate(dist):
#         if dist_i == 0:
#             continue
#         for j in range(dist_i, step+1): # 对于每个大于dist_i的step，都要修改第ind个值为s[ind - dist_i]
#             path[j-1][ind] = s[ind - dist_i]

    
#     print(step)
#     for i in path:
#         print("".join(i))



for _ in range(int(input())):
    m, n = map(int, input().split())
    s = list(input())
    t = list(input())
    path = []
    step = 0
    
    while s != t and step < n:
        ps = pt = len(s)-1
        r = len(s)-1
        while pt >= 0 and ps >= 0:
            if t[pt] != s[ps]:
                ps -= 1
            elif t[pt] == s[ps] and pt != ps:
                pt -= 1
            elif t[pt] == s[ps] and pt == ps:
                l = ps
                if l<r: # [l,r-1] 平移到 [l+1,r]
                    s[l+1:r+1] = s[l:r]
                r = l-1
                pt -= 1
                ps -= 1
        path.append(s.copy())
        step += 1
        if pt != ps:
            break
    
    

    if (s == t):
        print(step)
        for i in path:
            print("".join(i))
    else:
        print("-1")