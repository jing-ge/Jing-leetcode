def compute(l,r,k):
    res = 0
    for i in range(l,r+1):
        print(i)
        res =res+ (pow(i+pow(10,-k),1/3)-pow(i,1/3))
    return res

print(compute(1,1,15))