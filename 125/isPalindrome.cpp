//125. 验证回文串
//
//如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样，
//则可以认为该短语是一个 回文串 。
//
//字母和数字都属于字母数字字符。
//
//给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。

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