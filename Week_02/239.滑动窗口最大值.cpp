/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        if(n < k || k <= 0) return {};
        int low = 1 - k, high = 0;

        deque<int> dq;
        vector<int> res;
        while(high < n){
            if(low >= 1 && nums[low - 1] == dq[0])
                dq.pop_front();    //头部出队，清理超范围
            while(!dq.empty() && dq[0] < nums[high]) //
                dq.pop_front();  //弹出队首
            while(!dq.empty() && dq[dq.size() - 1]< nums[high])
                dq.pop_back();  //弹出队尾

            dq.push_back(nums[high]);   //放进队尾
            if(low >= 0) res.push_back(dq[0]); 
            low++;
            high++;
        }
        return res;
    }
};
// @lc code=end
/*暴力法
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if(nums.size() == 0) return res;
        for(int j =0; j < nums.size() - k + 1; j++){
            int max=-999;
            for(int i = j; i < j+k; i++){
                if(max < nums[i])
                    max = nums[i];
            }
            res.push_back(max);
        }
        return res;
    }
};
*/
