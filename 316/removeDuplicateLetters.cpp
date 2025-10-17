#include<iostream>
using namespace std;
#include<vector>

// 思路：对每个字母，在多个位置中选择
// 1. 

class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ss(s.size(), '0');
        string ans;
        vector<int> letters[26]; //存储字母出现位置
        for (int i = 0; i < s.size(); i++)
            letters[s[i] - 'a'].push_back(i);
        
        //按出现次数升序遍历字母
        for (int i = 1; ; i++)  
        {
            int flag = 0;
            for (int j = 0; j < 26; j++)    
            {
                if (letters[j].size() == 0)
                    continue;
                if (letters[j].size() > flag)
                    flag = letters[j].size();

                //对出现次数为 i 的字母
                if (letters[j].size() == i)     //寻找最小序号：在更小字母后，且尽量靠前
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