// 199. 二叉树的右视图

// 给定一个二叉树的 根节点 root，想象自己站在它的右侧，
// 按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

#include <iostream>
#include <vector>
#include <queue>
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
	vector<int> rightSideView(TreeNode *root)
	{
		if (!root)
			return {};

		vector<int> res;
		vector<vector<int>> level_order = levelOrder(root);
		for (auto a : level_order)
		{
			res.push_back(a.back());
		}

		return res;
	}

	vector<vector<int>> levelOrder(TreeNode *root)
	{
		if (root == nullptr)
			return {};

		vector<vector<int>> res;
		queue<TreeNode *> q;
		q.push(root);
		while (!q.empty())
		{
			vector<int> level;
			int len = q.size();
			for (int i = 0; i < len; i++)
			{
				TreeNode *tr = q.front();
				q.pop();
				level.push_back(tr->val);

				if (tr->left)
					q.push(tr->left);
				if (tr->right)
					q.push(tr->right);
			}
			res.push_back(move(level));
		}

		return res;
	}
	/*
		vector<int> rightSideView(TreeNode *root)
		{
			if (root == nullptr)
				return {};

			vector<int> l_view = rightSideView(root->left);
			vector<int> r_view = rightSideView(root->right);

			if (l_view.size() > r_view.size())
				r_view.insert(r_view.end(), l_view.begin() + r_view.size(), l_view.end());

			r_view.insert(r_view.begin(), root->val);
			return r_view;
		}
	*/
};