# s = "applepenapple", wordDict = ["apple", "pen"]
# 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
# 输出: false

s = "applepenapple"
wordDict = ["apple", "pen"]

s2 = "catsandog"
wordDict2 = ["cats", "dog", "sand", "and", "cat"]

def isComposed(s,wordDict):
    wordDict = set(wordDict)
    maxLen = 0
    for i in wordDict:
        maxLen = max(maxLen,len(i))
    return backtrace(0,s,wordDict,maxLen)


def backtrace(idx,s,wordDict,maxLen):
    if idx==len(s):
        return True
    for i in range(maxLen):
        tmp = s[idx:idx+i+1]
        if tmp in wordDict:
            if backtrace(idx+i+1,s,wordDict,maxLen):
                return True
    return False
print(isComposed(s,wordDict))
print(isComposed(s2,wordDict2))