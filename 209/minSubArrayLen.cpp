//209. ������С��������
//
//����һ������ n ���������������һ�������� target ��
//
//�ҳ����������������ܺʹ��ڵ��� target �ĳ�����С�� ������[numsl, numsl + 1, ..., numsr - 1, numsr] ��
//�������䳤�ȡ���������ڷ��������������飬���� 0 ��

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