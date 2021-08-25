string  =  "-12.345"

"12..45"
"++234"

def intTrans(s):
    res = 0
    for i in s:
        res = res*10 + int(i)
    if res>2**32-1 or res<-2**32:
        return None
    return res
def floatTrans(a,b):
    t = b
    a = intTrans(a)
    b = intTrans(b)
    b = b/(10**len(b))
    return a+b

def trans(s):
    flag = True
    if s[0]=="-":
        flag = False
    idx = -1
    for i in range(len(s)):
        if s[i]=='.':
            idx = i
    if idx == -1:
        if flag:
            return intTrans(s)
        else:
            return -intTrans(s[1:])
    else:
        if flag:
            return floatTrans(s[0:idx],s[0:idx])
        else:
            return -floatTrans(s[0:idx],s[0:idx])
res = -12.345
res = float(string)