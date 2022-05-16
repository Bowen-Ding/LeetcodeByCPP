#include <bits//stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

/*
字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。返回一个表示每个字符串片段的长度的列表。

示例：
输入：S = "ababcbacadefegdehijhklij"
输出：[9,7,8]
解释：
划分结果为 "ababcbaca", "defegde", "hijhklij"。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。

提示：
S的长度在[1, 500]之间。
S只包含小写字母 'a' 到 'z' 。
*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last[26];
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            last[s[i] - 'a'] = i; // C++刷题中记录字母位置常用方法
        }

        vector<int> partition;
        int start = 0, end = 0;
        for (int i = 0; i < n; ++i) {
            end = max(end, last[s[i] - 'a']);
            if (i == end) {
                partition.push_back(end - start + 1);
                start = end + 1;
            }
        }

           
        return partition;
    } 
};