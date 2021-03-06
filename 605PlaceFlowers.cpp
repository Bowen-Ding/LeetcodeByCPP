#include <bits//stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

/*
题目描述:
假设有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花不能种植在相邻的地块上，它们会争夺水源，两者都会死去。
给你一个整数数组  flowerbed 表示花坛，由若干 0 和 1 组成，其中 0 表示没种植花，1 表示种植了花。另有一个数 n ，能否在不打破种植规则的情况下种入 n 朵花？能则返回 true ，不能则返回 false。

示例 1：
输入：flowerbed = [1,0,0,0,1], n = 1
输出：true

示例 2：
输入：flowerbed = [1,0,0,0,1], n = 2
输出：false
*/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int s = flowerbed.size(), prev = -1, cnt = 0;
        for (int i = 0; i < s; ++i) {
            if (flowerbed[i] == 1) {
                if (prev < 0) {
                    cnt += i / 2;
                } else {
                    cnt += (i - prev - 2) / 2;
                }
                prev = i;
            }
        }

        if (prev < 0) {
            cnt += (s + 1) / 2;
        } else {
            cnt += (s - prev - 1) / 2;
        }
        return cnt >= n;
    }
};