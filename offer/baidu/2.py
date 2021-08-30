class TreeNode():
    def __init__(self,val):
        self.val = val
        self.left = None
        self.right = None

def maxVal(root):
    if root==None:
        return float('inf')
    while root.right is not None:
        root = root.right
    return root.right.val

def isBST(root):
    if root==None:
        return True
    if root.left is not None and root.val<maxVal(root.left):
        return False
    if root.right is not None and root.val>maxVal(root.right):
        return False
    return True

def heightOfTree(root):
    if root==None:
        return 0
    left = heightOfTree(root.left)
    right = heightOfTree(root.right)
    res = max(left,right)
    return res+1