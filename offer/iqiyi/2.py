# 最大的正方形白色区域的面积
# 时间限制： 3000MS
# 内存限制： 589824KB
# 题目描述：
# 给定一个二值化图像（只包含0和1两个值的图像），至少包含一个像素点，1显示为白色，0显示为黑色，寻找图像中最大的正方形白色区域的面积。其中，输入为字符串格式。



# 输入描述
# M*N维二值化矩阵，矩阵元素取值=0或1

# 1, 0, 1, 0, 0;

# 1, 0, 1, 1, 1;

# 1, 1, 1, 1, 1;

# 1, 0, 0, 1, 0

# 其中，输入不为空，且";"表示矩阵的一行

# 输出描述
# 1构成的最大的矩形面积，如输入描述中结果为4


# 样例输入
# 1,0,1,0,0;1,0,1,1,1;1,1,1,1,1;1,0,0,1,0
# 样例输出
# 4

# 提示
# 可参考构造输入函数为：

# raw_input = input("")

# m = raw_input.split(';')

# matrix = []

# for line in m:

#     elements = line.split(',')

#     matrix.append(elements)

raw_input = input("")

m = raw_input.split(';')

matrix = []

for line in m:

    elements = line.split(',')

    matrix.append(elements)
# m = len(matrix)
# n = len(matrix[0])

# def getres(matrix,i,j):
#     res = 1
#     while res<min(m-i,n-j):
#         for t in range(res):
#             if matrix[i+t][j]=='0' or matrix[i][j+t]=='0':
#                 return res
#         res += 1
#     return res+1

# res = 0
# for i in range(m):
#     for j in range(n):
#         if matrix[i][j]=='1':
#             t = getres(matrix,i,j)-1
#             res = max(res,t*t)
# print(res)

n = len(matrix)
m = len(matrix[0])

for i in range(n):
    for j in range(m):
        matrix[i][j] = int(matrix[i][j])
        if j>0  and matrix[i][j]>0 and matrix[i][j-1]>0:
            matrix[i][j]+=matrix[i][j-1]
res = 0
for j in range(m):
    left = [-1]*n
    right = [n]*n
    stack = list()

    for i in range(n-1,-1,-1):
        while stack and matrix[i][j]<matrix[stack[-1]][j]:
            left[stack.pop()] = i
        stack.append(i)
    stack.clear()
    for i in range(n):
        while stack and matrix[i][j]<matrix[stack[-1]][j]:
            right[stack.pop()] = i
        stack.append(i)
    
    for i in range(n):
        width = right[i]-left[i]-1
        hight = matrix[i][j]
        if width==hight:
            area = width*hight
            res = max(res,area)
print(res)