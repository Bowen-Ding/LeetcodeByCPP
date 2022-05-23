
#include <bits//stdc++.h>
#include <vector>
using namespace std;

/*
题目描述
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

注意：
对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
如果 s 中存在这样的子串，我们保证它是唯一的答案。
 
示例 1：
输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"

示例 2：
输入：s = "a", t = "a"
输出："a"

示例 3:
输入: s = "a", t = "aa"
输出: ""
解释: t 中两个字符 'a' 均应包含在 s 的子串中，
因此没有符合条件的子字符串，返回空字符串。

提示：
1 <= s.length, t.length <= 10^5
s 和 t 由英文字母组成
*/

class Solution {
public:
    bool is_true(int* a){//判断a中的元素是否全部都小于等于0
        int i;
        for(i = 0; i <= 'z' - 'A' && a[i] <= 0; i++);
        return i>'z'-'A';
    }
    string minWindow(string s, string t) {
        int a['z'-'A'+1];
        memset(a, 0, sizeof(a));
        for(const char ch:t) a[ch-'A']++ ;
        int i=0, j=0, n=s.size();
        string answer;
        while(j<n){
            if(--a[s[j++]-'A'] == 0 && is_true(a)){ // 注意只有在一个数从正数减为0时我们才会执行is_true，而不是每次都判断，这样可以降低时间复杂度
                while(++a[s[i++]-'A'] <= 0); // 同理当一个值从0上升到1时就证明当前窗口已不符合题意，不用调用is_true函数来判断
                if(answer.size() == 0 || answer.size() > j-i) answer.assign(s.begin()+i-1, s.begin()+j);
            }
        }
        return answer;
    }
};