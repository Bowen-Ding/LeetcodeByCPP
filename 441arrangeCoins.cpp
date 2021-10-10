#include <bits//stdc++.h>
#include <vector>
using namespace std;

/*
题目描述:
统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。

请注意，你可以假定字符串里不包括任何不可打印的字符。

示例:
你总共有 n 枚硬币，并计划将它们按阶梯状排列。对于一个由 k 行组成的阶梯，其第 i 行必须正好有 i 枚硬币。阶梯的最后一行 可能 是不完整的。

给你一个数字 n ，计算并返回可形成 完整阶梯行 的总行数。

 

示例 1：


输入：n = 5
输出：2
解释：因为第三行不完整，所以返回 2 。
*/

class Solution {
public:
    int arrangeCoins(int n) {
        int s = floor((sqrt((long long)8 * n + 1) - 1)/2);
        return s;
    }
};