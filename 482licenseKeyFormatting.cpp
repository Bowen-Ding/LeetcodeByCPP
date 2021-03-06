#include <bits//stdc++.h>
#include <vector>
using namespace std;

/*
题目描述:
有一个密钥字符串 S ，只包含字母，数字以及 '-'（破折号）。其中， N 个 '-' 将字符串分成了 N+1 组。

给你一个数字 K，请你重新格式化字符串，使每个分组恰好包含 K 个字符。特别地，第一个分组包含的字符个数必须小于等于 K，但至少要包含 1 个字符。两个分组之间需要用 '-'（破折号）隔开，并且将所有的小写字母转换为大写字母。

给定非空字符串 S 和数字 K，按照上面描述的规则进行格式化。

 

示例 1：

输入：S = "5F3Z-2e-9-w", K = 4
输出："5F3Z-2E9W"
解释：字符串 S 被分成了两个部分，每部分 4 个字符；
     注意，两个额外的破折号需要删掉。
示例 2：

输入：S = "2-5g-3-J", K = 2
输出："2-5G-3J"
解释：字符串 S 被分成了 3 个部分，按照前面的规则描述，第一部分的字符可以少于给定的数量，其余部分皆为 2 个字符。
*/

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int len = s.size();
        string ans = "";
        int cnt = 0;
        for (int i = len - 1; i >= 0; i--){
            if (s[i] != '-') {
                if (cnt != k) {
                    ans = ans.insert(0, 1, toupper(s[i]));
                    cnt++;
                } else {
                    ans.insert(0, "-");
                    ans = ans.insert(0, 1, toupper(s[i]));
                    cnt = 1;
                }
            }
        }

        return ans;
    }
};