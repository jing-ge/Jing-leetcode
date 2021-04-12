n = int(input())
data = []
s = input().split(" ")
for i in s:
    data.append(int(i))
stack = [data]
res = -sum(data)
while len(stack)>0:
    t = stack.pop()
    res += sum(t)
    if len(t)>1:
        a = []
        b = []
        if max(t)==min(t):
            continue
        mid = (max(t)+min(t))/2
        for i in t:
            if i<=mid:
                a.append(i)
            else:
                b.append(i)
        stack.append(a)
        stack.append(b)
    # print(stack)
    # print(res)
print(res)