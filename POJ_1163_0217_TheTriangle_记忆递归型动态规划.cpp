/**
 * @file POJ_1163_0217_TheTriangle_DynamicProgramming.cpp
 * @author AlgoGoer
 * @date 2022-02-17
 * 
 * Figure 1 shows a number triangle. Write a program that calculates the highest sum of numbers passed 
 * on a route that starts at the top and ends somewhere on the base. 
 * Each step can go either diagonally down to the left or diagonally down to the right.
 * 
 * Input
 * Your program is to read from standard input. 
 * The first line contains one integer N: the number of rows in the triangle. 
 * The following N lines describe the data of the triangle. 
 * The number of rows in the triangle is > 1 but <= 100. The numbers in the triangle, all integers, are between 0 and 99.
 * 
 * Output
 * Your program is to write to standard output. The highest sum is written as an integer.
 */

/**
 * 求MaxSum(1,1)
 * 解题思路:
 * 用二维数组存放数字三角形
 * D(r,j):第r行第j个数字(r,j从1开始算)
 * MaxSum(r,j):从D(r,j)到底边的各条路径中，最佳路径的数字之和
 * 典型递归问题
 * D(r,j)出发，下一步只能走到D(r+1,j+1)或D(r+1,j)
 * 故对于N行的三角形:
 * if (r == N)
 *     MaxSum(r, j) = D(r, j)
 * else
 *     MaxSum(r, j) = Max{MaxSum(r+1, j), MaxSum(r+1, j+1)} + D(r, j)
 */

// 时间复杂度O(n^2),空间复杂度O(n^2)

#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;
int D[MAX][MAX];         // 二维数组存储数字三角形
int maxSum[MAX][MAX];    // 记忆-动态规划
int n;

/**
 * 重复计算太多
 * 如果采用递归，深度遍历每条路径，就存在大量重复计算，时间复杂度O(2^n)
 * 对于n=100，肯定超时
 */

/**
 * 改进(记忆递归型DP):
 * 如果每算出一个MaxSum(r, j),就保存起来，下次用到其值的时候直接取用，则可免去重复计算
 * 时间复杂度O(n^2),第i行第j列到底边和只需要计算一次
 * 因为三角形的数字总数是n(n+1)/2
 */
int MaxSum(int i, int j)     // 第i行第j列到底边最大和
{
    if (maxSum[i][j] != -1)  // -1代表未计算过,不是-1才计算从而避免重复计算
        return maxSum[i][j]; // 这样第i行第j列到底边和只需要计算一次
    if (i == n)              // 到底边了
        maxSum[i][j] = D[i][j];
    else
    {
        int x = MaxSum(i + 1, j);
        int y = MaxSum(i + 1, j + 1);
        maxSum[i][j] = max(x, y) + D[i][j];   // 更新maxSum[i][j]
    }
    
    return maxSum[i][j];
}
int main()
{
    int i, j;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            cin >> D[i][j];
            maxSum[i][j] = -1;
        }
    }        
    cout << MaxSum(1, 1) << endl;
}