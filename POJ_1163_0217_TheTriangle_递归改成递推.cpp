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
 * 递归写成递推
 * 时间复杂度O(n^2),空间复杂度O(n^2)
 * 最后一行先赋值,再从下往上递推
 */

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 101
int D[MAX][MAX];
int n;
int maxSum[MAX][MAX];
int main()
{
    int i, j;
    cin >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= i; j++)
            cin >> D[i][j];
    for (int i = 1; i <= n; ++i)
        maxSum[n][i] = D[n][i];  // 最后一行先赋值
    for (int i = n - 1; i >= 1; --i)
        for (int j = 1; j <= i; ++j)
            maxSum[i][j] = max(maxSum[i + 1][j], maxSum[i + 1][j + 1]) + D[i][j];
    cout << maxSum[1][1] << endl;
}