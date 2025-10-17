//27. �Ƴ�Ԫ��
//��ʾ
//����һ������ nums ��һ��ֵ val������Ҫ ԭ�� �Ƴ�������ֵ���� val ��Ԫ�ء�
//Ԫ�ص�˳����ܷ����ı䡣Ȼ�󷵻� nums ���� val ��ͬ��Ԫ�ص�������
//
//���� nums �в����� val ��Ԫ������Ϊ k��Ҫͨ�����⣬����Ҫִ�����²�����
//
//���� nums ���飬ʹ nums ��ǰ k ��Ԫ�ذ��������� val ��Ԫ�ء�nums ������Ԫ�غ� nums �Ĵ�С������Ҫ��
//���� k��

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