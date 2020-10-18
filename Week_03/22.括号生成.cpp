/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    void Func(vector<string>& vec, string str, int left, int right, int n){
        if(left == n && right == n)
            vec.push_back(str);
        if(left < n) Func(vec, str + '(', left + 1, right, n);
        if(right < left) Func(vec, str + ')', left, right + 1, n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        Func(vec,"", 0, 0,n);
        return vec;
    }
};

// @lc code=end

