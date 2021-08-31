
def getres(t):
    return (t-1)//3
N = int(input())
res = []
for i in range(N):
    t = int(input())
    res.append(getres(t))
for i in res:
    print(i)