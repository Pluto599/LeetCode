#include<iostream>
using namespace std;
#include<vector>

// ˼·����ÿ����ĸ���ڶ��λ����ѡ��
// 1. 

class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ss(s.size(), '0');
        string ans;
        vector<int> letters[26]; //�洢��ĸ����λ��
        for (int i = 0; i < s.size(); i++)
            letters[s[i] - 'a'].push_back(i);
        
        //�����ִ������������ĸ
        for (int i = 1; ; i++)  
        {
            int flag = 0;
            for (int j = 0; j < 26; j++)    
            {
                if (letters[j].size() == 0)
                    continue;
                if (letters[j].size() > flag)
                    flag = letters[j].size();

                //�Գ��ִ���Ϊ i ����ĸ
                if (letters[j].size() == i)     //Ѱ����С��ţ��ڸ�С��ĸ���Ҿ�����ǰ
                {   
                    int index = 0;
                    for (int k = 0; k < ss.size(); k++)
                    {
                        if (index >= i)
                        {
                            ss[letters[j][0]] = char(j + 'a');
                            break;
                        }
                        if (k >= letters[j][index])
                            index++;

                        if (ss[k] == '0')
                            continue;
                        else if (ss[k] < (j + 'a'))
                        {
                            ss[letters[j][index]] = char(j + 'a');
                            break;
                        }
                    }
                    letters[j].clear();
                }
            }
            if (flag == 0)
                break;
        }

        for (int i = 0; i < ss.size(); i++)
            if (ss[i] != '0')
                ans += ss[i];
        return ans;
    }
};

int main()
{
    Solution a;
    cout << a.removeDuplicateLetters("ecbacbac");

    return 0;
}