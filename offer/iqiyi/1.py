# 日志排序
# 时间限制： 3000MS
# 内存限制： 589824KB
# 题目描述：
# 一个同学的程序在运行过程中产生日志，这些日志都是按照时间来命名，如20210503.log、20210504.log，该同学需要每隔一段时间删除日期上最早的3天的日志以防止硬盘被写满，那么请帮助这个同学设计一个算法找出这最早的3天日志（注1：当日志数量不足3天时，返回数组中包含全部的日志；注2：作为返回结果的数组要求是有序的）。



# 输入描述
# 一组，共n个日志名称，每个元素之间有一个空格隔开。

# 输出描述
# 输出一行数据，表示最早的3天日志名称，每个元素之间有一个空格隔开。


# 样例输入
# 20200501 20200502 20200503
# 样例输出
# 20200501 20200502 20200503

import time

logs = input().split(' ')
times = []
for i in logs:
    times.append(time.mktime(time.strptime(i,"%Y%m%d")))
# print(times)
times = sorted(times)
res = ""
for i in range(min(len(times),3)):
    s = time.strftime("%Y%m%d",time.localtime(times[i])) 
    res+=s+" "
print(res[:-1])

import time

# logs = input().split(' ')
# logs = sorted(logs)
# res = ""
# for i in range(min(len(logs),3)):
#     res+=logs[i]+" "
# print(res[:-1])