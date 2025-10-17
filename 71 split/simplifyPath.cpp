// 71. 简化路径

// 给你一个字符串 path ，表示指向某一文件或目录的 Unix 风格 绝对路径 （以 '/' 开头），
// 请你将其转化为 更加简洁的规范路径。

// 在 Unix 风格的文件系统中规则如下：

// 一个点 '.' 表示当前目录本身。
// 此外，两个点 '..' 表示将目录切换到上一级（指向父目录）。
// 任意多个连续的斜杠（即， '//' 或 '///'）都被视为单个斜杠 '/'。 任何其他格式的点（例如， '...' 或 '....'）均被视为有效的文件 /
// 目录名称。
// 返回的 简化路径 必须遵循下述格式：

// 始终以斜杠 '/' 开头。
// 两个目录名之间必须只有一个斜杠 '/' 。 最后一个目录名（如果存在）不能 以 '/' 结尾。
// 此外，路径仅包含从根目录到目标文件或目录的路径上的目录（即，不含 '.' 或 '..'）。 返回简化后得到的 规范路径 。

#include <iostream>
#include <stack>
#include <sstream>
#include <vector>
using namespace std;

class Solution
{
public:
	string simplifyPath(string path)
	{
		vector<string> split_path = split(path, '/');
	}

	vector<string> split(string str, char delim)
	{
		vector<string> ret;
		string tmp;

		istringstream iss(str);
		while (getline(iss, tmp, delim))
		{
			if (!tmp.empty())
			{
				ret.push_back(tmp);
			}
		}

		return ret;
	}

	/*
	string simplifyPath(string path)
	{
		string ans;

		stack<string> st;
		string cur_path;

		path += '/';
		for (char c : path)
		{
			if (c == '/')
			{
				if (!cur_path.empty() && cur_path != ".")
				{
					if (cur_path == "..")
					{
						if (!st.empty())
						{
							st.pop();
						}
					}
					else
					{
						st.push(cur_path);
					}
				}
				cur_path.clear();
			}
			else
			{
				cur_path += c;
			}
		}

		stack<string> rev_st;
		string tmp;
		while (!st.empty())
		{
			tmp = st.top();
			st.pop();
			rev_st.push(tmp);
		}

		while (!rev_st.empty())
		{
			ans += '/';
			tmp = rev_st.top();
			ans += tmp;
			rev_st.pop();
		}
		if (ans.empty())
		{
			ans += '/';
		}

		return ans;
	}
	*/
};

int main()
{
	Solution s;
	string str = "/a//b////c/d//././/..";

	cout << s.simplifyPath(str);
	return 0;
}