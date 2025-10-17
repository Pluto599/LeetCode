//27. 移除元素
//提示
//给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素。
//元素的顺序可能发生改变。然后返回 nums 中与 val 不同的元素的数量。
//
//假设 nums 中不等于 val 的元素数量为 k，要通过此题，您需要执行以下操作：
//
//更改 nums 数组，使 nums 的前 k 个元素包含不等于 val 的元素。nums 的其余元素和 nums 的大小并不重要。
//返回 k。

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = nums.size();
        for (int x : nums)
        {
            if (x == val)
                k--;
        }

        int p1 = 0;
        int p2 = k;
        for (; p1 < k && p2 < nums.size(); p1++)
        {
            if (nums[p1] == val)
            {
                while (nums[p2] == val)
                    p2++;

                swap(nums, p1, p2);
            }
        }

        for (int i = 0; i < k; i++)
            cout << nums[i] << ' ';
        cout << endl;

        return k;
    }

    void swap(vector<int>& n, int i, int j)
    {
        int temp = n[i];
        n[i] = n[j];
        n[j] = temp;
    }
};

int main()
{
    Solution s;
    vector<int> n = { 0,1,2,2,3,0,4,2 };
    int v = 2;

    cout << s.removeElement(n, v);

	return 0;
}