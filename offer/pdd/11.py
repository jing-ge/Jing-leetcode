# 1
# 3 4 1
# 5 2 3
# 1 2 9 7

N = int(input())
fres = []
def getres(red,blue,k):
    red.sort()
    blue.sort()
    n = len(red)
    m = len(blue)
    lr = 0
    lb = 0
    res = 0
    while lr<n and lb<m:
        if abs(red[lr]-blue[lb])<=k:
            lr+=1
            lb+=1
            res+=1
        else:
            if red[lr]>blue[lb]:
                lb+=1
            else:
                lr+=1
    return res

for i in range(N):
    line = input().split(' ')
    n = int(line[0])
    m = int(line[1])
    k = int(line[2])
    red = input().split(' ')
    blue = input().split(' ')
    for i in range(len(red)):
        red[i] = int(red[i])
    for i in range(len(blue)):
        blue[i] = int(blue[i])
    res = getres(red,blue,k)
    fres.append(res)
for i in fres:
    print(i)
