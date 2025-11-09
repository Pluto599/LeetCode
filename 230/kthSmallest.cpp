// 230. 二叉搜索树中第 K 小的元素

// 给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 小的元素（从 1 开始计数）。

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
private:
	int res = -1;
	int idx;

public:
	// 3. 递归
	int kthSmallest(TreeNode *root, int k)
	{
		idx = k;
		inOrder(root);
		return res;
	}

	void inOrder(TreeNode *root)
	{
		if (!root)
			return;

		inOrder(root->left);

		idx--;
		if (idx == 0)
			res = root->val;

		inOrder(root->right);
	}

	// 2. 迭代
	// int kthSmallest(TreeNode *root, int k)
	// {
	// 	TreeNode *cur = root;
	// 	stack<TreeNode *> st;

	// 	while (root || !st.empty())
	// 	{
	// 		while (cur)
	// 		{
	// 			st.push(cur);
	// 			cur = cur->left;
	// 		}

	// 		cur = st.top();
	// 		st.pop();
	// 		k--;
	// 		if (k == 0)
	// 		{
	// 			return cur->val;
	// 		}

	// 		cur = cur->right;
	// 	}

	// 	return -1;
	// }

	// 1. 中序遍历
	// int kthSmallest(TreeNode *root, int k)
	// {
	// 	vector<int> list = inOrder(root);
	// 	return list[k - 1];
	// }

	// vector<int> inOrder(TreeNode *root)
	// {
	// 	if (!root)
	// 		return {};

	// 	vector<int> res;

	// 	if (root->left)
	// 	{
	// 		auto left = inOrder(root->left);
	// 		res.insert(res.end(), left.begin(), left.end());
	// 	}

	// 	res.push_back(root->val);

	// 	if (root->right)
	// 	{
	// 		auto right = inOrder(root->right);
	// 		res.insert(res.end(), right.begin(), right.end());
	// 	}

	// 	return res;
	// }
};

int main()
{
	TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(3);
	root->left->left = new TreeNode(2);
	root->left->left->left = new TreeNode(1);
	root->left->right = new TreeNode(4);
	root->right = new TreeNode(6);

	Solution s;
	cout << s.kthSmallest(root, 3);

	return 0;
}