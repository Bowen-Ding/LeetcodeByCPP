#include <bits//stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

/*
题目描述:
给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a^2 + b^2 = c 。

示例 1：
输入：c = 5
输出：true
解释：1 * 1 + 2 * 2 = 5

示例 2：
输入：c = 3
输出：false
 
提示：
0 <= c <= 2^31 - 1
*/

class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0, right = (int)sqrt(c);
        while (left <= right) {
            long num = left * left + right * right;
            if (c == num) {
                return true;
            } else if (c > num) {
                ++left;
            } else {
                --right;
            }
        }

        return false;
    }
};
