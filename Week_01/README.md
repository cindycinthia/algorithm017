# 学习笔记 #

#数组array

------
283移动零解法 //一维数组的坐标变换，i j
1.loop,count zeros
2.开新数组，loop
3.index
五遍刷题法
**50% feedback
**题解，去掉-cn去国际站
最大的误区是刷题只刷一遍
核心思想就是：第一升维，第二空间换时间
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] != 0){
                nums[j] = nums[i];
                if(i !=j){   //如果i!=j,说明出现了nums[]=0的元素，此时为数组赋值0
                    nums[i]=0;
                }
                j++;
            }
        }
    }
};
------
11盛最多水的容器
1.枚举：left bar x, right bar y, (x-y)*height_min
O(n^2)
int maxArea(vector<int>& height) { //i和j不会重复
        for(int i = 0; i < height.size()-1; ++i){
            for(int j = i+1; j < height.size(); ++j)
        }
    }
2.O(n) 左右边界 i , j ,向中间收敛 左右夹逼
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        for(int i = 0, j = height.size()-1; i < j; ){
            int minHeight = height[i] < height[j] ? height[i ++] :height[j --]; //
            int area = (j - i + 1)* minHeight; //找大的那一个
            if(max < area ){
                max = area;
            }
        }
        return max;
    }
};
------
70.爬楼梯
懵逼的时候
暴力？ 基本情况？

找 最近 重复子问题

if else, for while, recuision

f(n)=f(n-1) + f(n-2)
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        int f1 = 1, f2 = 2, f3;
        for (int i=3; i <= n; i++){
            f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
        }
        return f3;
    }
------
# *15三数之和 #
a+b=-c(target)
1.暴力求解：三重循环
2.hash:两重暴力+hash
3.夹逼 ：因为不需要下标，可以排序后夹逼*
------
1两数之和
暴力法
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> tar;
        int i,j;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    tar.push_back(i);
                    tar.push_back(j);
                return tar;
                }
            }
        }
       return tar;
    }
};
一遍哈希表
...
俩遍哈希表
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i = 0; i<nums.size(); i++)
            m[nums[i]] = i;         //向map中添加元素        
        for(int i = 0; i<nums.size(); i++)
        {
            if(m.find(target-nums[i]) != m.end() && m[target-nums[i]] != i)  //如果m中存在对应的键值，且不为i
                return {i, m[target-nums[i]]};
        }
        return {};

    }
};
------
#链表linked list
------
206反转链表

------
24两两交换链表中的节点

------
141环形链表

------
142环形链表2

------
25K个一组翻转链表

------

------
#跳表skip list

#栈stack
LIFO
Stack<integer>stack = new Stack<>();
stack.push(1)
stack.pop()
int topelement=stack.peek()
stack.serch(3) "3的位置"

#队列queue
FIFO
Queue<string> queue = new LinkedList<string>();
queue.offer("one")
queue.poll()
queue.peek()
queue.size()

add,remove:抛出异常
#优先队列Priority Queue
插入O(1)
取出O(logN)
底层实现较为多样和复杂：heap、bst(binary search tree)、treap

#双端队列deque
Deque<String>deque = new LinkedList<String>();
deque.push("a")
deque.peek()
deque.pop()

