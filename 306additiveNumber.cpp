
#include <bits//stdc++.h>
#include <vector>
using namespace std;

/*
题目描述
累加数 是一个字符串，组成它的数字可以形成累加序列。

一个有效的 累加序列 必须 至少 包含 3 个数。除了最开始的两个数以外，字符串中的其他数都等于它之前两个数相加的和。

给你一个只包含数字 '0'-'9' 的字符串，编写一个算法来判断给定输入是否是 累加数 。如果是，返回 true ；否则，返回 false 。

说明：累加序列里的数 不会 以 0 开头，所以不会出现 1, 2, 03 或者 1, 02, 3 的情况。

 

示例 1：

输入："112358"
输出：true 
解释：累加序列为: 1, 1, 2, 3, 5, 8 。1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
示例 2：

输入："199100199"
输出：true 
解释：累加序列为: 1, 99, 100, 199。1 + 99 = 100, 99 + 100 = 199
 

提示：

1 <= num.length <= 35
num 仅由数字（0 - 9）组成
*/


class Solution {
private:
    string num;
    int n;
    vector<vector<int>> list;

public:
    bool isAdditiveNumber(string _num) {
        this->num = _num;
        n = _num.size();
        return dfs(0);
    }

    bool dfs(int u){// dfs 回溯函数,u表示从第u个字符开始分割
        int m = list.size(); // 表示已经确定的数字数量
        if (u == n) return m >= 3; //递归出口,遍历完后,判断是不是至少有3个数
        int max = num[u] == '0' ? u + 1 : n; // 本次遍历范围,u不为0可以搜索到结尾,否则只能单0
        vector<int> cur;

        // 从u开始遍历
        for (int i = u; i < max; i++) {
            // 倒叙插入每一位
            cur.insert(cur.begin(), num[i] - '0');
            // list不足2个或符合累加规则则进入递归
            if (m < 2 || check(list[m -2], list[m - 1], cur)) {
                // 回溯
                list.push_back(cur);
                if ( dfs(i + 1)) return true;
                list.pop_back();
            }
        }

        // 全部不符合返回false
        return false;
    }

    // 高精度加法,倒序存储,例: 123 -> [3,2,1]
    bool check(vector<int>& a,vector<int>& b,vector<int>& c) {
        vector<int> sum;
        int m = a.size(), n = b.size(), carry = 0;

        // 模拟进位加法
        for (int i = 0; i < m || i < n || carry != 0; i++){
            if (i < m) carry += a[i];
            if (i < n) carry += b[i];
            sum.push_back(carry % 10);
            carry /= 10;
        }

        bool ok = c.size() == sum.size();
        for ( int i = 0;i < c.size() && ok; i++) {
            if (c[i] != sum[i]) return false;
        }

        return ok;
    }

};