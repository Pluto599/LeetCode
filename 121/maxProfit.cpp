// ����һ������ prices �����ĵ� i ��Ԫ�� prices[i] ��ʾһ֧������Ʊ�� i ��ļ۸�
// ��ֻ��ѡ�� ĳһ�� ������ֻ��Ʊ����ѡ���� δ����ĳһ����ͬ������ �����ù�Ʊ��
// ���һ���㷨�����������ܻ�ȡ���������
// ��������Դ���ʽ����л�ȡ�������������㲻�ܻ�ȡ�κ����󣬷��� 0 ��

// ���룺[7,1,5,3,6,4]

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int max_profit = 0;
        int n = prices.size();
        // vector<int> latter_max(n);
        // latter_max[n - 1] = 0;

        //for (int i = n - 2; i >= 0; i--)
        //{
        //    latter_max[i] = max(latter_max[i + 1], prices[i + 1]);
        //}

        //for (int i = n-1; i >= 0; i--)
        //{
        //    max_profit = max(max_profit, latter_max[i] - prices[i]);
        //}

        //int prev_max = 0;
        //for (int i = n - 2; i >= 0; i--)
        //{
        //    int cur_max = max(prev_max, prices[i + 1]);
        //    max_profit = max(max_profit, cur_max - prices[i]);

        //    prev_max = cur_max;
        //}

        int min_idx = 0;
        for (int i = 1; i < n; i++)
        {
            min_idx = (prices[min_idx] < prices[i - 1] ? min_idx : i - 1);
            max_profit = max(max_profit, prices[i] - prices[min_idx]);
        }

        return max_profit;
    }
};

int main()
{
    Solution s;
    vector<int> prices{ 7,1,5,3,6,4 };

    cout << s.maxProfit(prices);
}