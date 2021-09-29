import math
n = int(input())
line = input().split(' ')
weights = {}
for i in range(n):
    weights[i+1] = int(line[i])
line2 = input().split(' ')
graph = {}
for i in range(n-1):
    t = i+2
    p = int(line2[i])
    if p in graph.keys():
        graph[p].append(t)
    else:
        graph[p] = [int(t)]
path = [1]
def dfs(node,path,result):
    if node not in graph:
        return result
    else:
        for newnode in graph[node]:
            for father in path:
                if math.sqrt(weights[father]*weights[newnode])%1==0:
                    result+=1
            path.append(newnode)
            result = dfs(newnode,path,result)
            path.pop()
        return result
res = dfs(1,path,0)
# print(weights)
# print(graph)
print(res)
