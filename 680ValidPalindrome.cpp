#include <bits//stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

/*
题目描述:
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

示例 1:
输入: s = "aba"
输出: true

示例 2:
输入: s = "abca"
输出: true
解释: 你可以删除c字符。

示例 3:
输入: s = "abc"
输出: false
 
提示:
1 <= s.length <= 105
s 由小写英文字母组成
*/

class Solution {
public:
    bool isPalindrome(string& s, int a, int b) {
        while (a <= b) {
            if (s[a] != s[b] ) {
                return false;
            } else {
                ++a;
                --b;
            }
        }

        return true;
    }

    bool validPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n -1;
        while (l <= r) {
            if (s[l] != s[r]) {
                int l1 = l + 1, r1 = r - 1;
                return isPalindrome(s, l1, r) || isPalindrome(s, l, r1);
            } else {
                ++l;
                --r;
            }
        }
        return true;
    }
};