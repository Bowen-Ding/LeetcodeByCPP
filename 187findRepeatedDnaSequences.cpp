#include <bits//stdc++.h>
#include <vector>
using namespace std;

/*
题目描述
所有 DNA 都由一系列缩写为 'A'，'C'，'G' 和 'T' 的核苷酸组成，例如："ACGAATTCCG"。在研究 DNA 时，识别 DNA 中的重复序列有时会对研究非常有帮助。

编写一个函数来找出所有目标子串，目标子串的长度为 10，且在 DNA 字符串 s 中出现次数超过一次。

 

示例 1：

输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
输出：["AAAAACCCCC","CCCCCAAAAA"]
示例 2：

输入：s = "AAAAAAAAAAAAA"
输出：["AAAAAAAAAA"]
*/


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int len = s.length();
        vector<string> ans;
        unordered_map<string, int> cnt;

        for (int i = 0; i <= len - 10; i++){
            string tmp = s.substr(i, 10);
            if(++cnt[tmp] == 2){
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};