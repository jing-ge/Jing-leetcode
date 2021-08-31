T = int(input())
res = []
def getres(d):
    if len(d)==0:
        return 0
    if len(d)==1:
        return 1
    t = min(d)
    res = t
    for i in range(len(d)):
        d[i]-=t
    data = []
    l = 0
    r = 0
    
    while r<len(d):
        while l<len(d) and d[l]==0:
            l+=1
        r = l
        while r<len(d) and d[r]!=0:
            r+=1
        data.append(d[l:r])
        l = r
    for i in data:
        res+=getres(i)
    return min(res,len(d))

for i in range(T):
    N = int(input())
    line = input().split(' ')
    for i in range(len(line)):
        line[i] = int(line[i])
    res.append(getres(line))
for i in res:
    print(i)