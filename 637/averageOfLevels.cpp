// 637. 二叉树的层平均值

// 给定一个非空二叉树的根节点 root,
// 以数组的形式返回每一层节点的平均值。与实际答案相差 10 - 5 以内的答案可以被接受。

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
	vector<double> averageOfLevels(TreeNode *root)
	{
		if (!root)
			return {};

		vector<double> level_sum;
		vector<int> level_length;

		queue<TreeNode *> q;
		q.push(root);

		while (!q.empty())
		{
			int len = q.size();
			level_sum.push_back(0);
			level_length.push_back(len);

			for (int i = 0; i < len; i++)
			{
				TreeNode *tr = q.front();
				q.pop();

				level_sum.back() += tr->val;

				if (tr->left)
					q.push(tr->left);
				if (tr->right)
					q.push(tr->right);
			}
		}

		for (int i = 0; i < level_sum.size(); i++)
		{
			level_sum[i] = level_sum[i] / level_length[i];
		}

		return level_sum;
	}
};

int main()
{
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	Solution s;
	vector<double> avg = s.averageOfLevels(root);
	for (auto a : avg)
		cout << a << ' ';

	return 0;
}