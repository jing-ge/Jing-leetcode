n = int(input())
A = input().split(" ")
B = input().split(" ")
C = input().split(" ")
for i in range(n):
    A[i] = int(A[i])
    B[i] = int(B[i])
    C[i] = int(C[i])

res = 0
# A.sort()
# B.sort()
# C.sort()
# for i in range(n):
#     t = min(A[0],B[0],C[0])
#     if t==A[0]:
#         A.pop(0)
#         B.pop()
#         C.pop()
#     elif t==B[0]:
#         A.pop()
#         B.pop(0)
#         C.pop()
#     else:
#         A.pop()
#         B.pop()
#         C.pop(0)
#     res += t
D = A+B+C
D.sort()

print(sum(D[:n]))