n = int(input())
data = []
for i in range(n):
    tlen = int(input())
    d = {}
    for _ in range(tlen):
        k = input()
        if k in d.keys():
            d[k]+=1
        else:
            d[k] = 1
    data.append(d)

keys = []
for d in data:
    keys+=d.keys()
keys = list(set(keys))
keyscount = {}
for d in data:
    for k in d.keys():
        if k in keyscount.keys():
            keyscount[k]+=1
        else:
            keyscount[k]=1

for d in data:
    t = 0
    for k in d.keys():
        t = max(t,d[k]/keyscount[k])
    print(t)