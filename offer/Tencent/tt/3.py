line = input().split(' ')
n = int(line[0])
k = int(line[1])
line = input().split(' ')
for i in range(len(line)):
    line[i] = int(line[i])
res = float('inf')
for t in range(n-k):
    ll= line[:t]+line[t+k:]
    mid = line[t:t+k]
    r = sum(mid)/len(mid)
    maxx = max(max(ll),r)
    minn = min(min(ll),r)
    res = min(res,maxx-minn)
print(res)