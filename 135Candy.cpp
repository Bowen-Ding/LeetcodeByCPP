#include <bits//stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

/*
题目描述:
一群孩子站成一排，每一个孩子有自己的评分。现在需要给这些孩子发糖果，规则是如果一
个孩子的评分比自己身旁的一个孩子要高，那么这个孩子就必须得到比身旁孩子更多的糖果；所
有孩子至少要有一个糖果。求解最少需要多少个糖果。
输入输出样例
输入是一个数组，表示孩子的评分。输出是最少糖果的数量。
Input: [1,0,2]
Output: 5
在这个样例中，最少的糖果分法是 [2,1,2]。
*/

class Solution {
public:
    // 两次遍历,先从左到右,只与左边比较;再从右到左,只与右边比较
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if (size < 2) {
            return size;
        }
        vector<int> num(size, 1);
        for (int i = 1; i < size; ++i) {
            if (ratings[i] > ratings[i-1]) {
                num[i] = num[i-1] + 1;
            }
        }

        for (int i = size - 1; i > 0; --i) {
            if ( ratings[i] < ratings[i-1]) {
                num[i-1] = max(num[i-1],num[i] + 1);
            }
        }
        return accumulate(num.begin(), num.end(), 0);
    }
};