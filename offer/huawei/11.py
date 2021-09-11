N = int(input())
graph = []
for i in range(N):
    graph.append([])
cost = []
for i in range(N):
    line = input().replace('  ',' ')
    line = line.split(' ')
    if len(line)>2:
        for t in line[2:]:
            graph[int(t)].append(i)
    cost.append(int(line[1]))
dp = [float('inf')]*N
dp[0] = cost[0]
for i in range(1,N):
    tmp = 0
    for t in graph[i]:
        tmp = max(tmp,dp[t])
    dp[i] = tmp+cost[i]
# print(cost)
# print(graph)
# print(dp)
print(max(dp))
# 4
# softmax 10 1 2
# relu 5
# conv1 1 3
# softmax 2