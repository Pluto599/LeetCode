//228. ��������
//
//����һ��  ���ظ�Ԫ�� �� ���� �������� nums ��
//
//����[a, b] �Ǵ� a �� b�������������������ļ��ϡ�
//
//���� ǡ�ø����������������� �� ��С���� ���䷶Χ�б� ��
//Ҳ����˵��nums ��ÿ��Ԫ�ض�ǡ�ñ�ĳ�����䷶Χ�����ǣ����Ҳ���������ĳ�����䵫������ nums ������ x ��
//
//�б��е�ÿ�����䷶Χ[a, b] Ӧ�ð����¸�ʽ�����
//
//"a->b" ����� a != b
//"a" ����� a == b

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