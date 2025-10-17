// 88. 合并两个有序数组
// 给你两个按 非递减顺序 排列的整数数组 NUMS1 和 NUMS2，
// 另有两个整数 M 和 N ，分别表示 NUMS1 和 NUMS2 中的元素数目。
// 请你 合并 NUMS2 到 NUMS1 中，使合并后的数组同样按 非递减顺序 排列。
// 
// 注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。
// 为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。
// nums2 的长度为 n 。
// 

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = 0, p2 = 0;

        vector<int> nums0 = nums1;

        int i = 0;
        for (; i < m + n && p1 < m && p2 < n; i++)
        {
            if (nums0[p1] < nums2[p2])
            {
                nums1[i] = nums0[p1];
                p1++;
            }
            else
            {
                nums1[i] = nums2[p2];
                p2++;
            }
        }

        while (p1 < m)
        {
            nums1[i] = nums0[p1];
            i++;
            p1++;
        }
        while (p2 < n)
        {
            nums1[i] = nums2[p2];
            i++;
            p2++;
        }

        /*for (int i = 0; i < m + n; i++)
        {
            cout << nums1[i] << endl;
        }*/
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = { 1,2,3,0,0,0 };
    int m = 3;
    vector<int> nums2 = { 2,5,6 };
    int n = 3;

    s.merge(nums1, m, nums2, n);

	return 0;
}