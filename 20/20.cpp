// 20. 有效的括号

// 给定一个只包括 '('， ')'， '{'， '}'， '['， ']' 的字符串 s ，判断字符串是否有效。

// 有效字符串需满足：

// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。 每个右括号都有一个对应的相同类型的左括号。

#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
	bool isValid(string s)
	{
		stack<char> st;

		for (char c : s)
		{
			if (isLeft(c))
			{
				st.push(c);
			}
			else
			{
				if (st.empty() || st.top() != rightToLeft(c))
				{
					return false;
				}
				else
				{
					st.pop();
				}
			}
		}

		if (st.empty())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isLeft(char c)
	{
		return c == '(' || c == '{' || c == '[';
	}
	char rightToLeft(char c)
	{
		if (c == ')')
			return '(';
		if (c == '}')
			return '{';
		if (c == ']')
			return '[';
		return '\0'; // Return null character for invalid input
	}
};

int main()
{
	Solution s;
	string ss = "({[[()]]})";

	cout << s.isValid(ss);
	return 0;
}