n=7
k=3
def getres
res = 0
for i in range(k+1,n+1):
    res+=n//i
    tmp = n%i
    if tmp>=k:
        res+=1
print(res)