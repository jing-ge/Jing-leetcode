from queue import Queue
line = input().split(' ')
n = int(line[0])
q = int(line[1])

child = []
parnet = []
state = [0]*n
def run(x,y):
    y = y-1
    q = Queue()
    q.put(y)
    if x==1:
        while q.qsize()>0:
            t = q.get()
            if state[t]==1:
                continue
            else:
                for i in child[t]:
                    q.put(i)
                state[t] = 1
        return sum(state)
    else:
        while q.qsize()>0:
            t = q.get()
            if state[t]==0:
                continue
            else:
                for i in parnet[t]:
                    q.put(i)
                state[t] = 0
        return sum(state)
res = []
for i in range(n):
    child.append([])
    parnet.append([])
for i in range(n):
    line = input().strip().split(' ')
    if len(line)>1:
        for t in line[1:]:
            child[i].append(int(t)-1)
            parnet[int(t)-1].append(i)
for i in range(q):
    line = input().strip().split(' ')
    res.append(run(int(line[0]),int(line[1])))
for i in res:
    print(i)
# print(child)
# print(parnet)
# print(res)