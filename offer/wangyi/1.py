import functools
def cmp(a,b):
    if a[1]>b[1]:
        return -1
    elif a[1]<b[1]:
        return 1
    else:
        if a[0]>b[0]:
            return 1
        elif a[0]<b[0]:
            return -1
        else:
            return 0
    return 0
line = input().split(' ')
n = int(line[0])
m = int(line[1])
data = {}
id2name = {}
for i in range(n):
    line = input().split(' ')
    id2name[line[0]] = line[1]
for i in range(m):
    line = input().split(' ')
    uid = line[0]
    act = line[1]
    score = int(line[2])
    if uid in data.keys():
        data[uid][0].add(act)
        data[uid][1]+=score
    else:
        data[uid] = [set([act]),score]
res = []
for k,v in data.items():
    if len(v[0])>=0:
        res.append([id2name[k],v[1]])
print(res)
res = sorted(res,key=functools.cmp_to_key(cmp))
for i in res:
    print(i[0],i[1])
