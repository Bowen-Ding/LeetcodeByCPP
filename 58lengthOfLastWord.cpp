#include <bits//stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

/*
题目描述:
给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中最后一个单词的长度。

单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。

示例 1：
输入：s = "Hello World"
输出：5

示例 2：
输入：s = "   fly me   to   the moon  "
输出：4

示例 3：
输入：s = "luffy is still joyboy"
输出：6
*/

class Solution {
public:
    // 反向遍历,先找到最后一个字母所在的索引,然后逐渐前移并且计数,直接移到空格位或者索引归零
    int lengthOfLastWord(string s) {
        int index = s.length() - 1;
        while ( s[index] == ' ') {
            index--;
        }
        int wordLength = 0;
        while ( index >= 0 && s[index] != ' ') {
            wordLength++;
            index--;
        }
        return wordLength;
    }
};