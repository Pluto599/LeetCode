// 88. �ϲ�������������
// ���������� �ǵݼ�˳�� ���е��������� NUMS1 �� NUMS2��
// ������������ M �� N ���ֱ��ʾ NUMS1 �� NUMS2 �е�Ԫ����Ŀ��
// ���� �ϲ� NUMS2 �� NUMS1 �У�ʹ�ϲ��������ͬ���� �ǵݼ�˳�� ���С�
// 
// ע�⣺���գ��ϲ������鲻Ӧ�ɺ������أ����Ǵ洢������ nums1 �С�
// Ϊ��Ӧ�����������nums1 �ĳ�ʼ����Ϊ m + n������ǰ m ��Ԫ�ر�ʾӦ�ϲ���Ԫ�أ��� n ��Ԫ��Ϊ 0 ��Ӧ���ԡ�
// nums2 �ĳ���Ϊ n ��
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