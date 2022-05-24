#include <bits//stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

/*
题目描述:
Given a string, find the length of the longest substring T that contains at most k distinct characters.

For example, Given s = “eceba” and k = 2,

T is "ece" which its length is 3.
*/

class Solution {
public:
    // 双指针l、r从下标0开始，移动r,当区间字母种类>k时,移动l,直到r到达终点,记录过程中区间<=k的最大长度
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.size();
        int l = 0, r = 0, maxl = 0;
        unordered_map<char, int> hash;
        while (r < n) {
            hash[s[r++]]++;
            while (hash.size() > k) {
                hash[s[l]]--;
                if (hash[s[l]] == 0) {
                    hash.erase(s[l]);
                }
                l++;
            }
            maxl = max(maxl, r - l);
        }

        return maxl;
    }
};