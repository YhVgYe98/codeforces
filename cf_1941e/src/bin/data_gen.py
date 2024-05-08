import random
import numpy as np

out = '1\n'
for j in range(1):
    # n=int(random.random()*4)+1             # row
    # k=int(random.random()*(n-1))+1          # bridge num
    # m=int(random.random()*(10))+3    # col
    # d=int(random.random()*(m-1))+1          # max distance
    n=1
    k=1
    m=20000
    d=1
    out += "{} {} {} {}\n".format(n,m,k,d)
    depth = np.random.randint(0,1000,[n,m-2])
    if (depth.sum()>20000):
        depth = np.random.randint(0,1000001,[n,m-2])
    depth = np.concatenate((np.zeros([n,1],dtype=np.int32),depth,np.zeros([n,1],dtype=np.int32)),axis=1)
    for x in range(n):
        for y in range(m):
            out += "{} ".format(depth[x,y])
        out += "\n"
print(out)