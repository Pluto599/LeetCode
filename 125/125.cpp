//125. ��֤���Ĵ�
//
//����ڽ����д�д�ַ�ת��ΪСд�ַ������Ƴ����з���ĸ�����ַ�֮�󣬶������Ŷ��ͷ��Ŷ���һ����
//�������Ϊ�ö�����һ�� ���Ĵ� ��
//
//��ĸ�����ֶ�������ĸ�����ַ���
//
//����һ���ַ��� s��������� ���Ĵ� ������ true �����򣬷��� false ��

#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for (char c : s)
        {
            if (isValid(c))
            {
                toLittle(c);
                t += c;
            }

        }

        int i = 0, j = t.size() - 1;
        for (; i < j; i++, j--)
        {
            if (t[i] != t[j])
                return false;
        }

        return true;
    }

    bool isValid(char c)
    {
        return (c >= '0' && c <= '9') 
            || (c >= 'A' && c <= 'Z') 
            || (c >= 'a' && c <= 'z');
    }

    void toLittle(char& c)
    {
        if (c >= 'A' && c <= 'Z')
            c += 'a' - 'A';
    }
};

int main()
{
    Solution s;
    string str = "A man, a plan, a canal: Panama";

    cout<<s.isPalindrome(str);

    return 0;
}