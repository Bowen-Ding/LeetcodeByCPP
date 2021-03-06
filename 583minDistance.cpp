#include <bits//stdc++.h>
#include <vector>
using namespace std;

/*
题目描述:
给定两个单词 word1 和 word2，找到使得 word1 和 word2 相同所需的最小步数，每步可以删除任意一个字符串中的一个字符。

 

示例：

输入: "sea", "eat"
输出: 2
解释: 第一步将"sea"变为"ea"，第二步将"eat"变为"ea"
*/


class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= m; i++){
            char c1 = word1[i - 1];
            for ( int j = 1; j <= n; j++){
                char c2 = word2[j - 1];
                if ( c1 == c2) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1] [j]);
                }
            }
        }

        int lcs = dp[m][n];
        return m - lcs + n - lcs;
    }
};