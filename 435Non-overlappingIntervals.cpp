#include <bits//stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

/*
题目描述:
给定多个区间，计算让这些区间互不重叠所需要移除区间的最少个数。起止相连不算重叠。
输入输出样例
输入是一个数组，数组由多个长度固定为 2 的数组组成，表示区间的开始和结尾。输出一个
整数，表示需要移除的区间数量。
Input: [[1,2], [2,4], [1,3]]
Output: 1
在这个样例中，我们可以移除区间 [1,3]，使得剩余的区间 [[1,2], [2,4]] 互不重叠。
*/

class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });

		int res = 0, prev = intervals[0][1];
		for (int i = 1; i < intervals.size(); ++i) {
			if (intervals[i][0] < prev) {
                ++res;
            } else {
                prev = intervals[i][1];
            }
		}
		return res;
	}
};