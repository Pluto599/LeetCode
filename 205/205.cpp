//205. ͬ���ַ���
//
//���������ַ��� s �� t ���ж������Ƿ���ͬ���ġ�
//
//��� s �е��ַ����԰�ĳ��ӳ���ϵ�滻�õ� t ����ô�������ַ�����ͬ���ġ�
//
//ÿ�����ֵ��ַ���Ӧ��ӳ�䵽��һ���ַ���ͬʱ���ı��ַ���˳��
//��ͬ�ַ�����ӳ�䵽ͬһ���ַ��ϣ���ͬ�ַ�ֻ��ӳ�䵽ͬһ���ַ��ϣ��ַ�����ӳ�䵽�Լ�����

#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
        {
            return false;
        }

        int n = s.size();
        map<char, char> m1;
        map<char, char> m2;
        for (int i = 0; i < n; i++)
        {
            if (!m1.count(s[i]))
            {
                m1.insert({ s[i],t[i] });
            }
            if (!m2.count(t[i]))
            {
                m2.insert({ t[i],s[i] });
            }

            if (t[i] != m1[s[i]] || s[i]!=m2[t[i]])
            {
                return false;
            }
            
        }

        return true;
    }
};

int main()
{
    Solution ss;
    string s = "paper";
    string t = "title";

    cout << ss.isIsomorphic(s, t);

    return 0;
}