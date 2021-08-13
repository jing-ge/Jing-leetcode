def FarmerNN(n , m ):
    # write code here
    res = [0]*n
    t = 0
    flag = True
    for i in range(m):
        print(t)
        res[t]+=1
        if t==n-1:
            flag = False
        if t==0:
            flag = True
        if flag:
            t+=1
        else:
            t-=1
    return res
print(FarmerNN(4,6))