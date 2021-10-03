#include <bits//stdc++.h>
#include <vector>
#include <list>
using namespace std;

/*
给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以 字符串形式返回小数 。

如果小数部分为循环小数，则将循环的部分括在括号内。

如果存在多个答案，只需返回 任意一个 。

对于所有给定的输入，保证 答案字符串的长度小于 104 。

 

示例 1：

输入：numerator = 1, denominator = 2
输出："0.5"
示例 2：

输入：numerator = 2, denominator = 1
输出："2"
示例 3：

输入：numerator = 2, denominator = 3
输出："0.(6)"
示例 4：

输入：numerator = 4, denominator = 333
输出："0.(012)"
示例 5：

输入：numerator = 1, denominator = 5
输出："0.2"
*/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if((int64_t)numerator % denominator == 0) return to_string((int64_t)numerator / denominator);

        int64_t up = abs((int64_t)numerator), down = abs((int64_t)denominator);
        string ans(((numerator < 0) ^ (denominator < 0) ? "-" : "") + to_string(up / down) + '.');
        unordered_map<int64_t, int> index;

        for(int i = ans.size(); up = up % down * 10; ++i){
            if(index.count(up)) {
                ans.insert(begin(ans) + index[up], '(');
                ans.push_back(')');
                break;
            }
            index[up] = i;
            ans.push_back('0' + up / down);
        }
        return ans;
    }
};