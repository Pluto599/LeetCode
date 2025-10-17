#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int eraseOverlapIntervals(vector<vector<int>> &intervals)
	{
		int n = intervals.size();
		if (n == 0)
			return 0;
		// ������ʱ����������
		sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
			 { return a[1] < b[1]; });

		vector<int> dp(n, 1); // dp[i] ��ʾ�Ե�i������Ϊ��β������ص�������

		for (int i = 1; i < n; ++i)
		{
			// ���ֲ���j
			int left = 0, right = i - 1, j = -1;
			while (left <= right)
			{
				int mid = left + (right - left) / 2;
				if (intervals[mid][1] <= intervals[i][0])
				{
					j = mid;
					left = mid + 1;
				}
				else
				{
					right = mid - 1;
				}
			}
			if (j != -1)
				dp[i] = max(dp[i - 1], dp[j] + 1);
			else
				dp[i] = max(dp[i - 1], 1);
		}
		// ������ݼ��ϵĴ�СΪdp[n-1]
		// ��Ҫ�������Ƴ����ٸ�����ʹ�����䲻�ص�����Ϊ n - dp[n-1]
		return n - dp[n - 1];
	}
};