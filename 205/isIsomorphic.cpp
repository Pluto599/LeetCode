//205. 同构字符串
//
//给定两个字符串 s 和 t ，判断它们是否是同构的。
//
//如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。
//
//每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。
//不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。

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