// 200. 岛屿数量

// 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

// 岛屿总是被水包围，并且每座岛屿只能由水平方向和 / 或竖直方向上相邻的陆地连接形成。

// 此外，你可以假设该网格的四条边均被水包围。

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
private:
	// vector<vector<pair<int, int>>> parent;
	int m, n;

public:
	// 2. dfs
	int numIslands(vector<vector<char>> &grid)
	{
		m = grid.size();
		n = grid[0].size();

		int res = 0;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (grid[i][j] == '1')
				{
					res++;
					dfs(grid, i, j);
				}
	}

	void dfs(vector<vector<char>> &grid, int i, int j)
	{
		if (grid[i][j] == '0')
			return;

		grid[i][j] = '0';
		if (i > 0)
			dfs(grid, i - 1, j);
		if (j > 0)
			dfs(grid, i, j - 1);
		if (i < m - 1)
			dfs(grid, i + 1, j);
		if (j < n - 1)
			dfs(grid, i, j + 1);
	}

	// 1. 手写并查集
	// int numIslands(vector<vector<char>> &grid)
	// {
	// 	int m = grid.size();
	// 	int n = grid[0].size();

	// 	parent.resize(m, vector<pair<int, int>>(n, {-1, -1}));

	// 	for (int i = 0; i < m; i++)
	// 		for (int j = 0; j < n; j++)
	// 		{
	// 			if (grid[i][j] == '1')
	// 			{
	// 				if (j != n - 1 && grid[i][j + 1] == '1')
	// 					Union({i, j}, {i, j + 1});
	// 				if (i != m - 1 && grid[i + 1][j] == '1')
	// 					Union({i, j}, {i + 1, j});
	// 			}
	// 		}

	// 	int res = 0;
	// 	for (int i = 0; i < m; i++)
	// 		for (int j = 0; j < n; j++)
	// 			if (grid[i][j] == '1' && parent[i][j].first < 0)
	// 				res++;

	// 	return res;
	// }

	// pair<int, int> Find(pair<int, int> x)
	// {
	// 	return parent[x.first][x.second].first < 0 ? x : Find(parent[x.first][x.second]);
	// }

	// void Union(pair<int, int> x, pair<int, int> y)
	// {
	// 	pair<int, int> px = Find(x);
	// 	pair<int, int> py = Find(y);
	// 	if (px == py)
	// 		return;

	// 	int &sx = parent[px.first][px.second].first;
	// 	int &sy = parent[py.first][py.second].first;
	// 	if (sx <= sy)
	// 	{
	// 		sx += sy;
	// 		parent[py.first][py.second] = px;
	// 	}
	// 	else
	// 	{
	// 		sy += sx;
	// 		parent[px.first][px.second] = py;
	// 	}
	// }
};

int main()
{
	Solution s;
	vector<vector<char>> grid = {
		{'1', '1', '0', '0', '0'},
		{'1', '1', '0', '0', '0'},
		{'0', '0', '1', '0', '0'},
		{'0', '0', '0', '1', '1'}};

	cout << s.numIslands(grid);

	return 0;
}
