dic = {'1':"一",'2':'二','3':'三','4':'四','5':'五','6':'六','7':'七','8':'八','9':'九','0':'零'}
danwei = ['万','千','百','十','亿','千','百','十','万','千','百','十']

num = 123000089

def trans(num):
    res = ""
    num = str(num)
    if len(num)==0:
        return res
    elif len(num)==1:
        return dic[num[0]]
    else:
        idx = len(num)-1
        res+=dic[num[idx]]
        dw = len(danwei)-1
        idx-=1
        while idx>=0:
            if num[idx+1]=='0' and num[idx]=='0':
                if danwei[dw]=='万' or danwei[dw]=='亿':
                    res = danwei[dw] + res
                idx-=1
                dw-=1
                continue
            if num[idx]=='0':
                res = dic[num[idx]] +res
            else:
                res = dic[num[idx]]+danwei[dw] +res
            idx-=1
            dw-=1
    return res


print(trans(num))