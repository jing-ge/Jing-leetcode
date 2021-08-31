# 2
# dcba
# abcd
import functools
d = []

N = int(input())
for i in range(N):
    d.append(input())
def mysort(x,y):
    global d
    xx = [x]
    lx = len(x)
    for i in range(lx):
        tmp = list(x)
        t = tmp[i]
        tmp[i] = tmp[lx-1-i]
        tmp[lx-1-i] = t
        xx.append(''.join(tmp))
    yy = [y]
    ly = len(y)
    for i in range(ly//2):
        tmp = list(y)
        t = tmp[i]
        tmp[i] = tmp[ly-1-i]
        tmp[ly-1-i] = t
        yy.append(''.join(tmp))
    #xx.sort()
    #yy.sort()
    mx = min(xx)
    my = min(yy)
    if mx<my:
        return -1
    if my<mx:
        return 1
    idx = 0
    idy = 0
    for i in range(len(d)):
        if d[i]==x:
            idx = i
        if d[i]==y:
            idy = i
    if idx<idy:
        return -1
    elif idx>idy:
        return 1
    else:
        return 0
d = sorted(d,key=functools.cmp_to_key(mysort))
# print(d)
for i in d:
    print(i)
