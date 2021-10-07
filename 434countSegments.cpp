#include <bits//stdc++.h>
#include <vector>
using namespace std;

/*
题目描述:
统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。

请注意，你可以假定字符串里不包括任何不可打印的字符。

示例:

输入: "Hello, my name is John"
输出: 5
解释: 这里的单词是指连续的不是空格的字符，所以 "Hello," 算作 1 个单词。
*/

class Solution {
public:
    int countSegments(string s) {
        if (s == "") return 0;
        int len = s.length();
        int tmp = -2, cnt = 0;
        for (int i = 0; i < len; i++){
            if (s[i] != ' '){
                if (i - tmp > 1) cnt++;
                tmp = i;
            }
        }
        return cnt;
    }
};