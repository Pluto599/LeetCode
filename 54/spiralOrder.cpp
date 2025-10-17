//54. 螺旋矩阵
//
//提示
//给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int m, n;
    int left_row, right_row, up_column, down_column;
    vector<int> ans;

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        

        left_row = 0, right_row = n - 1, up_column = 0, down_column = m - 1;

        while (left_row <= right_row && up_column <= down_column)
        {
            for (int i = 1; i < 5; i++)
            {
                get(matrix, i);
                if (ans.size() >= m * n)
                    break;
            }
        }

        return ans;
    }

    void get(vector<vector<int>>& matrix, int i)
    {
        switch (i)
        {
            case 1: 
                get1(matrix);
                break;
            case 2:
                get2(matrix);
                break;
            case 3:
                get3(matrix);
                break;
            case 4:
                get4(matrix);
                break;
        }

    }

    void get1(vector<vector<int>>& matrix)
    {
        for (int i = left_row; i <= right_row; i++)
        {
            ans.push_back(matrix[up_column][i]);
        }

        up_column++;
    }

    void get2(vector<vector<int>>& matrix)
    {
        for (int j = up_column; j <= down_column; j++)
        {
            ans.push_back(matrix[j][right_row]);
        }

        right_row--;
    }

    void get3(vector<vector<int>>& matrix)
    {
        for (int i = right_row; i >= left_row; i--)
        {
            ans.push_back(matrix[down_column][i]);
        }

        down_column--;
    }

    void get4(vector<vector<int>>& matrix)
    {
        for (int j = down_column; j >= up_column; j--)
        {
            ans.push_back(matrix[j][left_row]);
        }

        left_row++;
    }
};

int main()
{
    vector<vector<int>> m = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
    Solution s;
     
    vector<int> ans = s.spiralOrder(m);
    for (int i : ans)
        cout << i << ' ';

    return 0;
}