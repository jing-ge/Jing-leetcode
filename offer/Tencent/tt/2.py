T = int(input())
def getres(n,d):
    if n/3>d:
        return 1
    else:
        return 0
res = []
for _ in range(T):
    line = input().split(' ')
    res.append(getres(int(line[0]),int(line[1])))
for i in res:
    print(i)