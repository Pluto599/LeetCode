//383. �����
//
//���������ַ�����ransomNote �� magazine ���ж� ransomNote �ܲ����� magazine ������ַ����ɡ�
//
//������ԣ����� true �����򷵻� false ��
//
//magazine �е�ÿ���ַ�ֻ���� ransomNote ��ʹ��һ�Ρ�

#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> m;
        for (char c : magazine)
        {
            if (!m.count(c))
            {
                m.insert({ c,1 });
            }
            else
            {
                m[c]++;
            }
        }

        for (char c : ransomNote)
        {
            if (m.count(c))
            {
                m[c]--;
                if (m[c] == 0)
                {
                    m.erase(c);
                }
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution s;
    string r = "aa";
    string m = "ab";

    cout << s.canConstruct(r, m);

    return 0;
}