//3. 无重复字符的最长子串
// 
//提示
//给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。

#include<iostream>
#include<set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int begin = 0, end = 0;
        int max_len = 0;
        set<char> inSub;

        //while (begin < s.size())
        //{
        //    if (inSub.find(s[begin]) != inSub.end()) // 有相同字符
        //    {
        //        while (s[end] != s[begin])
        //        {
        //            inSub.erase(s[end]);
        //            end++;
        //        }
        //        end++;
        //    }
        //    max_len = max(max_len, begin - end + 1);

        //    inSub.insert(s[begin]);
        //    begin++;
        //}

        inSub.insert(s[0]);
        end = 1;
        for (; begin < s.size(); begin++)
        {
            while (end < s.size() && inSub.find(s[end]) == inSub.end())
            {
                inSub.insert(s[end]);
                end++;
            }
            max_len = max(max_len, end - begin);

            inSub.erase(s[begin]);
        }

        return max_len;
    }
};

int main()
{
    string str = "abcabcbb";
    Solution s;

    cout << s.lengthOfLongestSubstring(str);

	return 0;
}