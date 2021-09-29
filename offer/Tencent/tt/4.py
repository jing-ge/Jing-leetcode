from queue import Queue
q = int(input())
def bfs(t,x,y):
    q = Queue()
    q.put([x,y])
    dir_ma = [[2,1],[1,2],[-2,-1],[-1,-2],[2,-1],[1,-2],[-2,1],[-1,2]]
    dir_xiang = [[2,2],[2,-2],[-2,2],[-2,-2]]
    if t==1:
        res_dir = dir_ma
    elif t==2:
        res_dir = dir_xiang
    elif t==3:
        res_dir = dir_ma+dir_xiang
    res = 0
    while q.qsize()>0:
        n = q.qsize()
        for _ in range(n):
            t = q.get()
            if t[0]==1 and t[1]==1:
                return res
            for d in res_dir:
                if 400>=t[0]+d[0]>=1 and 400>=t[1]+d[1]>=1:
                    q.put([t[0]+d[0],t[1]+d[1]])
        res+=1
    return -1
res = []
for _ in range(q):
    line = input().split(' ')
    t = int(line[0])
    x = int(line[1])
    y = int(line[2])
    res.append(bfs(t,x,y))
for i in res:
    print(i)