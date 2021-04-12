import math
def compute(l,r,k):
    res = 0
    for i in range(l,r+1):
        res += math.pow(i+math.pow(10,-k),1/3)-math.pow(i,1/3)
    return res
n = int(input())
res = []
for i in range(n):
    s = input().split(" ")
    res.append(compute(int(s[0]),int(s[1]),int(s[2])))

for i in res:
    print(i)