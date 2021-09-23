#include <bits//stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

/*
题目描述:
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

示例 1：
输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。

示例 2：
输入：nums = [0,1,0,3,2,3]
输出：4

示例 3：
输入：nums = [7,7,7,7,7,7,7]
输出：1
*/

class Solution {
public:
    // 动态规划: dp[i]是以第i个数字结尾的最长上升子序列的长度;
    // 时间复杂度:O(n^2),空间复杂度: O(n)
    int lengthOfLIS1(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 0) {
            return 0;
        }
        vector<int> dp(n,0);
        for (int i = 0; i < n; i++){
            dp[i] = 1;
            for (int j = 0; j < i; j++){
                if (nums[j] < nums[i]){
                    dp[i] = max(dp[i],dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }

    // 贪心+二分查找算法: 数组d[i]表示长度为i的最长上升子序列末位元素的最小值
    int lengthOfLIS2(vector<int>& nums){
        int len = 1, n = (int)nums.size();
        if ( n == 0) {
            return 0;
        }
        vector<int> d(n+1,0);
        d[len] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > d[len]){
                d[++len] = nums[i];
            } else {
                int l = 1, r = len, pos = 0;//如果找不到说明所有的数都比nums[i]大,此时要更新d[l],所以这里将pos设为0
                while (l < r){
                    int mid = (l + r) >> 1;
                    if (d[mid] < nums[i]) {
                        pos = mid;
                        l = mid + 1;
                    }else{
                        r = mid - 1;
                    }
                }
                d[pos + 1] = nums[i];
            }
        }
        return len;
    }
};