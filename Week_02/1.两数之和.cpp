/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        //并不需要key有序，选择std::unordered_map 效率更高 
        for(int i=0; i<nums.size(); ++i){
            //find()返回的是迭代器
            auto it = hashtable.find(target - nums[i]);
            //如果找到，返回当前找到的value，和当前所在下标
            if(it != hashtable.end()){
                return {it->second, i};
            }
            //若未找到，将当前key value加入哈希表
            hashtable[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

