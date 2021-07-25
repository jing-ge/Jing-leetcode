N = int(input())
def isset(A,B,C,Q):
    d = [A]
    p1 = 0
    p2 = 0
    while True:
        m1 = d[p1]+B
        m2 = d[p2]*C
        t = min(m1,m2)
        if t==m1:
            p1+=1
        if t==m2:
            p2+=1
        d.append(t)
        if t==Q:
            return True
        if t>Q:
            return False
    return False
res = []
isset(3,3,3,7)
for i in range(N):
    s = input().split(" ")
    res.append(isset(int(s[0]),int(s[1]),int(s[2]),int(s[3])))

for i in res:
    if i:
        print(1)
    else:
        print(0)