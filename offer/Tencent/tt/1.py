T = int(input())
res = []
def rand_score(A,B):
    t = len(B)
    x = 0
    y = 0
    z = 0
    w = 0
    for i in range(t):
        for j in range(i+1,t):
            if A[i]==A[j]:
                if B[i]==B[j]:
                    x+=1
                else:
                    y+=1
            else:
                if B[i]==B[j]:
                    z+=1
                else:
                    w+=1
    return (x+w)/(x+y+z+w)
for i in range(T):
    line1 = input().split(' ')
    line2 = input().split(' ')
    line3 = input().split(' ')
    for i in range(len(line2)):
        line2[i] = int(line2[i])
        line3[i] = int(line3[i])
    r = rand_score(line2,line3)
    if r>0.5:
        res.append(1)
    else:
        res.append(0)
for i in res:
    print(i)