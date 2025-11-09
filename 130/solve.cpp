// 130. 被围绕的区域

// 给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' 组成，捕获 所有 被围绕的区域：

// 连接：一个单元格与水平或垂直方向上相邻的单元格连接。
// 区域：连接所有 'O' 的单元格来形成一个区域。
// 围绕：如果您可以用 'X' 单元格 连接这个区域，并且区域中没有任何单元格位于 board 边缘，则该区域被 'X' 单元格围绕。
// 通过 原地 将输入矩阵中的所有 'O' 替换为 'X' 来 捕获被围绕的区域。你不需要返回任何值。

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
	int m, n;

public:
	void solve(vector<vector<char>> &board)
	{
		m = board.size();
		n = board[0].size();

		for (int i = 0; i < m; i++)
		{
			if (board[i][0] == 'O')
				dfs(board, i, 0);
			if (board[i][n - 1] == 'O')
				dfs(board, i, n - 1);
		}
		for (int j = 0; j < n; j++)
		{
			if (board[0][j] == 'O')
				dfs(board, 0, j);
			if (board[m - 1][j] == 'O')
				dfs(board, m - 1, j);
		}

		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == 'O')
					board[i][j] = 'X';
				if (board[i][j] == 'T')
					board[i][j] = 'O';
			}
	}

	void dfs(vector<vector<char>> &board, int i, int j)
	{
		if (board[i][j] != 'O')
			return;
		board[i][j] = 'T';

		if (i > 0)
			dfs(board, i - 1, j);
		if (j > 0)
			dfs(board, i, j - 1);
		if (i < m - 1)
			dfs(board, i + 1, j);
		if (j < n - 1)
			dfs(board, i, j + 1);
	}
};