n=7
k=3

res = 0
for i in range(k+1,n+1):
    res+=n//i
    tmp = n%i
    if tmp>=k:
        res+=tmp-k+1
print(res)