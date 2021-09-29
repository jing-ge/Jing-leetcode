class TreeNode():
    def __init__(self,x):
        self.val = x
        self.left = None
        self.right = None

from queue import Queue

def serialize(root):
    if root is None:
        return ""
    res = []
    q = Queue()
    q.put(root)

    while q.qsize()>0:
        n = q.qsize()
        for _ in range(n):
            tmp = q.get()
            if tmp:
                res.append(str(tmp.val))
                q.put(tmp.left)
                q.put(tmp.right)
            else:
                res.append('None')
    return "$".join(res)
def deserialize(s):
    arr = s.split('$')[::-1]
    root = TreeNode(int(arr.pop()))
    q = Queue()
    q.put(root)
    while q.qsize()>0:
        tmp = q.get()
        left = arr.pop()
        if left != 'None':
            tmp.left = TreeNode(int(left))
            q.put(tmp.left)
        right = arr.pop()
        if right != 'None':
            tmp.right = TreeNode(int(right))
            q.put(tmp.right)
    return root



node1 = TreeNode(1)
node2 = TreeNode(2)
node3 = TreeNode(3)
node4 = TreeNode(4)
node5 = TreeNode(5)
node6 = TreeNode(6)
node7 = TreeNode(7)

node4.left = node2
node4.right = node6

node2.left = node1
node2.right = node3

node6.left = node5
node6.right = node7

root = node4

sres = serialize(node4)
print(sres)

print(serialize(deserialize(sres)))