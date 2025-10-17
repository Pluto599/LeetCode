//228. 汇总区间
//
//给定一个  无重复元素 的 有序 整数数组 nums 。
//
//区间[a, b] 是从 a 到 b（包含）的所有整数的集合。
//
//返回 恰好覆盖数组中所有数字 的 最小有序 区间范围列表 。
//也就是说，nums 的每个元素都恰好被某个区间范围所覆盖，并且不存在属于某个区间但不属于 nums 的数字 x 。
//
//列表中的每个区间范围[a, b] 应该按如下格式输出：
//
//"a->b" ，如果 a != b
//"a" ，如果 a == b

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        vector<string> ans;
        int l, r;

        vector<string> summaryRanges(vector<int>& nums) {
            if (nums.empty())
                return ans;

            l = nums[0], r = nums[0];

            for (int i = 1; i < nums.size(); i++)
            {
                if (nums[i] == r + 1)
                {
                    r++;
                }
                else
                {
                    addRange();
                    l = r = nums[i];
                }
            }
            addRange();

            return ans;
        }

        void addRange()
        {
            char range[64];
            if (l == r)
            {
                snprintf(range, 64, "%d", l);
            }
            else
            {
                snprintf(range, 64, "%d->%d", l, r);
            }
            ans.push_back(range);
        }
    };

int main()
{
    Solution s;
    vector<int> n = { 0,1,2,4,5,7 };

    vector<string> str = s.summaryRanges(n);
    for (string x : str)
    {
        cout << x << ' ';
    }

    return 0;
}