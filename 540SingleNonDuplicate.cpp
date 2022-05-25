#include <bits//stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

/*
题目描述:
给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次。
请你找出并返回只出现一次的那个数。
你设计的解决方案必须满足 O(log n) 时间复杂度和 O(1) 空间复杂度。

示例 1:
输入: nums = [1,1,2,3,3,4,4,8,8]
输出: 2

示例 2:
输入: nums =  [3,3,7,7,10,11,11]
输出: 10

提示:
1 <= nums.length <= 10^5
0 <= nums[i] <= 10^5
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (mid % 2 == 1) mid -= 1;
            if (nums[mid] == nums[mid+1]) {
                l = mid + 2;
            } else {
                r = mid;
            }
        }
        return nums[l];
    }
};