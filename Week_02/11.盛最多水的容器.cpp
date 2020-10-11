/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1; //双指针
        int ans = 0;
        while(l < r){ 
            //公式算出最大容量，比较
            int area = min(height[l], height[r]) * (r - l);
            ans = max(ans, area);
            if(height[l] < height[r]){
                //如果左边小，左边指针移动，右边小，右边移动
                ++l;
            }
            else{
                --r;
            }
        }
        return ans;
    }
};
// @lc code=end

