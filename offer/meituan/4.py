 定义一个字符串为关键串，当且仅当该串中出现的最多字符严格超过了串长的一半

 输入：
第一行是一个正整数n表示字符串的长度
第二行是一个长度为n且仅包含小写字母的字符串s
输出：
输出一行，表示字符串s是关键串字串的个数

import collections
n = int(input())
strs = input()
def iskey(s):
    obj = collections.Counter(s)
    t = 0
    for k,v in obj.items():
        t = max(t,v)
    if t<=len(s)//2:
        
        return False
    else:
        print(s)
        return True
res = 0
for i in range(len(strs)):
    for j in range(i+1,len(strs)+1):
        if iskey(strs[i:j]):
            res+=1
print(res)