# 5 5 4
# 5 1 5 3 6
# 1 2 1
# 1 3 2
# 2 3 3
# 2 5 1
# 3 4 4

# 2, 12

line = input().split(' ')
n = int(line[0])
m = int(line[1])
P = int(line[2])
water = input().split(' ')
for i in range(len(water)):
    water[i] = int(water[i])
dis = [[-1]*n]*n
graph = []
for i in range(n):
    graph.append([])
d = []
for i in range(m):
    line = input().split(' ')
    d.append([int(line[0])-1,int(line[1])-1,int(line[2])])
for t in d:
    print(t[0],t[1])
    graph[t[0]].append([t[1],t[2]])
    graph[t[1]].append([t[0],t[2]])
for g in graph:
    g.sort(key=lambda x:x[1])
res = [0]*n

print(graph)
