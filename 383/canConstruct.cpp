//383. 赎金信
//
//给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
//
//如果可以，返回 true ；否则返回 false 。
//
//magazine 中的每个字符只能在 ransomNote 中使用一次。

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