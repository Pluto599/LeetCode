// 2 abc
// 3 def
// 4 ghi
// 5 jkl
// 6 mno
// 7 pqrs
// 8 tuv
// 9 wxyz
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<char> Num2Letts[10] = {
        {}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
    /*vector<string> Num2Letts[10] = {
        {},{},{"a","b","c"},{"d","e","f"},
        {"g","h","i"},{"j","k","l"},{"m","n","o"},
        {"p","q","r","s"},{"t","u","v"},{"w","x","y","z"}
    };*/

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        int len = digits.size();
        int *numLen = new int[len]; // ���ֶ�Ӧ��ĸ�ĸ���
        int cnt = 1;                // �ܹ� cnt �����
        for (int i = 0; i < len; i++)
        {
            numLen[i] = (digits[i] == 7 || digits[i] == 9) ? 4 : 3;
            cnt *= numLen[i];
        }
        // cnt = fore * numLen[i] * rear;
        // ������numLen(3 or 4)����ͬ��ĸ * ÿ����ĸ�ظ�rear�� * fore��ѭ��
        // ��һ������
        int cur = digits[0] - '0';
        int fore = numLen[0];
        int rear = cnt / (fore * numLen[0]);
        for (int j = 0; j < numLen[0]; j++)
            for (int k = 0; k < rear; k++)
            {
                string temp = "";
                temp.push_back(Num2Letts[cur][j]);
                ans.push_back(temp);
            }
        // �� 2 to len ������
        for (int i = 1; i < len; i++)
        {
            cur = digits[i] - '0';
            rear = cnt / (fore * numLen[i]);
            for (int m = 0; m < fore; m++)
                for (int j = 0; j < numLen[i]; j++)
                    for (int k = 0; k < rear; k++)
                        ans[k + m * cnt / rear] += Num2Letts[cur][j];

            fore *= numLen[i];
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> ans = s.letterCombinations("23");
    for (auto a : ans)
        cout << a << ' ';
}

// 1 abc��2 de��3 fg                                    ÿ���ظ� rear ��, ѭ�� fore ��
// 1-->a,  a,  a,  a,  b,  b,  b,  b,  c,  c,  c,  c    ÿ���ظ� 2*2 ��
// 2-->ad, ad, ae, ae, bd, bd, be, be, cd, cd, ce, ce   ÿ���ظ� 2 ��, ѭ�� 3 ��
// 3-->adf,adg,aef,aeg,bdf,bdg,bef,beg,cdf,cdg,cef,ceg  ÿ���ظ� 1 �Σ�ѭ�� 3*2 ��
//