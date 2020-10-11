/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
/*1.将所有0移动到数组末尾
*2.所有非零元素必须保持其原始顺序
*/
//快慢指针
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int lastFoundNonZero = 0, cur = 0; cur  < nums.size(); cur ++){
            if(nums[cur] != 0){
                swap(nums[lastFoundNonZero++], nums[cur]);
            }
        }
    }
};
/*
class Solution {
public:
void moveZeroes(vector<int>& nums){
    int lastFoundNonZero = 0;
    for(int i = 0;i < nums.size(); i++){
        if(nums[i] != 0){
            nums[lastFoundNonZero++] = nums[i];
        }
    }
    for( int i = lastFoundNonZero; i < nums.size(); i++){
        nums[i]=0;
    }
}
};
*/
/*
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int numZeroes = 0;
        for(int i = 0; i < n; i++){
            numZeroes += (nums[i] == 0);
        }
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                ans.push_back(nums[i]);
            }
        }
        while(numZeroes--){
            ans.push_back(0);
        }
        for(int i = 0; i < n; i++){
            nums[i] = ans[i];
        }
    }
};
*/
// @lc code=end

