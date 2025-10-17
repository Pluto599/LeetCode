// 56. 合并区间

// 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [ starti, endi ] 。
// 请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &x, const vector<int> &y)
             {
                 return x[0] < y[0];
             });

        int begin = intervals[0][0], end = intervals[0][1];
        vector<vector<int>> ans;
        for (size_t i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= end)
            {
                end = max(end, intervals[i][1]);
            }
            else
            {

                ans.push_back({begin, end});

                begin = intervals[i][0];
                end = intervals[i][1];
            }
        }
        ans.push_back({begin, end});

        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> res = s.merge(intervals);
    for (const auto &interval : res)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }

    return 0;
}