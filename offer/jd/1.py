# 3
# 5 1 5
N = int(input())
nums = input().strip().split(' ')
for i in range(len(nums)):
    nums[i] = int(nums[i])
def cal(nums):
    nums.sort()
    mid = len(nums)//2
    less, great = nums[:mid],nums[mid:]
    return 2*(sum(great)-sum(less))-great[0]-(great[1] if len(nums) & 1 else -less[-1])
print(cal(nums))