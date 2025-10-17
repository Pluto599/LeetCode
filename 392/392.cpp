//392. �ж�������
//
//�����ַ��� s �� t ���ж� s �Ƿ�Ϊ t �������С�
//
//�ַ�����һ����������ԭʼ�ַ���ɾ��һЩ��Ҳ���Բ�ɾ�����ַ������ı�ʣ���ַ����λ���γɵ����ַ�����
//�����磬"ace"��"abcde"��һ�������У���"aec"���ǣ���
//
//���ף�
//
//����д�������� S������ S1, S2, ..., Sk ���� k >= 10�ڣ�����Ҫ���μ�������Ƿ�Ϊ T �������С�
//����������£���������ı���룿

#include<iostream>
using namespace std;

class Solution {
public:
	bool isSubsequence(string s, string t) {
		int ps = 0, pt = 0;
		while (ps < s.size() && pt < t.size())
		{
			if (s[ps] == t[pt])
			{
				ps++;
				pt++;
			}
			else
			{
				pt++;
			}
		}

		if (ps == s.size())
			return true;
		else
			return false;
	}
};

int main()
{
	string s = "axc";
	string t = "ahbgdc";
	Solution ss;

	cout << ss.isSubsequence(s, t);



	return 0;
}