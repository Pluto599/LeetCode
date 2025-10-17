#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
    //int f(vector<int>& nums, int i) 
    //{
    //    return i < nums.size() ? max(nums[i] + f(nums, i + 2), f(nums, i + 1)) : 0;
    //}

    int rob(vector<int>& nums) 
    { 
        //return f(nums, 0); 

        int n = nums.size();
        vector<int> dp(n + 1);
        dp[n] = 0;
        dp[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
        }

        return dp[0];
    }
};