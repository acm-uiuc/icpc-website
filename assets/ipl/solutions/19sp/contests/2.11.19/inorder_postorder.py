def check(inorder, postorder):
	if len(inorder) == len(postorder) == 0:
		return True
	if len(inorder) == len(postorder) == 1:
		return inorder[0] == postorder[0]
	root = postorder[-1]
	split = list(filter(lambda x: x[1] == root, enumerate(inorder)))
	if len(split) == 0:
		return False
	split = split[0][0]
	return check(inorder[: split], postorder[: split]) and check(inorder[split + 1: ], postorder[split: -1])

_ = int(input())
inorder = list(map(int, input().split()))
postorder = list(map(int, input().split()))
if check(inorder, postorder):
	print('Valid')
else:
	print('Invalid')