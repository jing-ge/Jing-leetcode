n = input()
strs = input()
count0=0
count1=0
i=0
while i <(len(strs)-2):
    flag = False
    if strs[i]=='0' and strs[i+1]=='0' and strs[i+2]=='0':
        count0+=3
        flag = True
    if strs[i]=='1' and strs[i+1]=='1' and strs[i+2]=='1':
        count1+=3
        flag = True
    if flag:
        i+=3
    else:
        i+=1
print(abs(count0-count1))