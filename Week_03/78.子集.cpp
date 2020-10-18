/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<int> t;
    vector<vector<int> > ans;
    void dfs(int cur, vector<int>& nums){
        if(cur == nums.size()){
            //记录答案
            ans.push_back(t);
            return;
        }
        //考虑选择当前位置
        t.push_back(nums[cur]); //用t数组存放已经被选出的数字
        dfs(cur + 1,nums);
        t.pop_back();
        //考虑不选择当前位置
        dfs(cur + 1,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return ans;
    }
};
// @lc code=end

