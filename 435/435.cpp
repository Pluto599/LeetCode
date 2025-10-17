//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
//        int n = intervals.size();
//        if (n == 0) return 0;
//        // 按结束时间升序排序
//        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
//            return a[1] < b[1];
//            });
//
//        vector<int> dp(n, 1); // dp[i] 表示以第i个区间为结尾的最大不重叠区间数
//
//        for (int i = 1; i < n; ++i) {
//            // 二分查找j
//            int left = 0, right = i - 1, j = -1;
//            while (left <= right) {
//                int mid = left + (right - left) / 2;
//                if (intervals[mid][1] <= intervals[i][0]) {
//                    j = mid;
//                    left = mid + 1;
//                }
//                else {
//                    right = mid - 1;
//                }
//            }
//            if (j != -1)
//                dp[i] = max(dp[i - 1], dp[j] + 1);
//            else
//                dp[i] = max(dp[i - 1], 1);
//        }
//        // 最大相容集合的大小为dp[n-1]
//        // 若要求最少移除多少个区间使得区间不重叠，则为 n - dp[n-1]
//        return n - dp[n - 1];
//    }
//
//};
#include <stdio.h>

int main() {
	printf("%x, %x, %x\n", 'd', 'o', 'g');
	return 0;
}