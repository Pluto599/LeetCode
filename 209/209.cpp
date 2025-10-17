//209. 长度最小的子数组
//
//给定一个含有 n 个正整数的数组和一个正整数 target 。
//
//找出该数组中满足其总和大于等于 target 的长度最小的 子数组[numsl, numsl + 1, ..., numsr - 1, numsr] ，
//并返回其长度。如果不存在符合条件的子数组，返回 0 。

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int head = 0, tail = 0;
        int min_len = INT_MAX;
        int sum = 0;

        while (head < nums.size())
        {
            sum += nums[head];

            while (sum >= target )
            {
                min_len = min(min_len, head - tail + 1);
                sum -= nums[tail];
                tail++;
            }

            head++;
        }
        if (min_len==INT_MAX)
            return 0;
        else
            return min_len;
    }
};

int main()
{
    Solution s;
    int t = 11;
    vector<int> n = { 1,2,3,4,5 };

    cout << s.minSubArrayLen(t, n);

	return 0;
}