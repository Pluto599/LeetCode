// 530. 二叉搜索树的最小绝对差

// 给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。

// 差值是一个正数，其数值等于两值之差的绝对值。

#include <iostream>
#include <vector>
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
public:
	int getMinimumDifference(TreeNode *root)
	{
		vector<int> list = unfold(root);

		int res = INT_MAX;
		for (int i = 1; i < list.size(); i++)
		{
			res = min(res, list[i] - list[i - 1]);
		}

		return res;
	}

	vector<int> unfold(TreeNode *root)
	{
		if (!root)
			return {};

		vector<int> res;

		if (root->left)
		{
			vector<int> l = unfold(root->left);
			res.insert(res.begin(), l.begin(), l.end());
		}
		res.push_back(root->val);
		if (root->right)
		{
			vector<int> r = unfold(root->right);
			res.insert(res.end(), r.begin(), r.end());
		}

		return res;
	}
};