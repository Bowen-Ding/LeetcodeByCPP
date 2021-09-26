#include <bits//stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

/*
题目描述:
给你两个整数 a 和 b ，不使用 运算符 + 和 - ​​​​​​​，计算并返回两整数之和。

 

示例 1：

输入：a = 1, b = 2
输出：3
示例 2：

输入：a = 2, b = 3
输出：5
*/

class Solution {
public:
    int getSum(int a, int b) {
        while ( b != 0) {
            unsigned int carry = (unsigned int)(a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};