N = int(input())
ddj = input().split(" ")
ddy = input().split(" ")

for i in range(N):
    ddj[i] = int(ddj[i])
    ddy[i] = int(ddy[i])
cddj = 0
cddy = 0
table = []
flag = False
while len(ddj)>0 or len(ddy)>0:
    if flag:
        flag = False
        if len(ddy)>0:
            t = ddy[0]
            ddy.pop(0)
            if t in table:
                while table[-1]!=t and len(table)>0:
                    cddy+=1
                    table.pop()
                table.pop()
                cddy+=2
                if len(ddy)>0:
                    continue
            else:
                table.append(t)
    else:
        if len(ddj)>0:
            t = ddj[0]
            ddj.pop(0)
            if t in table:
                while table[-1]!=t and len(table)>0:
                    cddj+=1
                    table.pop()
                table.pop()
                cddj+=2
                if len(ddj)>0:
                    continue
            else:
                table.append(t)
        if len(ddy)>0:
            t = ddy[0]
            ddy.pop(0)
            if t in table:
                while table[-1]!=t and len(table)>0:
                    cddy+=1
                    table.pop()
                table.pop()
                cddy+=2
                if len(ddy)>0:
                    table.append(ddy[0])
                    ddy.pop(0)
            else:
                table.append(t)
for i in table:
    if i%2==1:
        cddj+=1
    else:
        cddy+=1
print(cddj,cddy)



