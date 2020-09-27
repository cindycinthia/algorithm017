#语言C++
# 简单： #
用 add first 或 add last 这套新的 API 改写 Deque 的代码

Deque<String>deque = new LinkedList<String>();

deque.addLast("a");
deque.addLast("a")
deque.addLast("a")
cout<<deque<<endl;

string str = deque.getLast();
cout<<str<<endl;
cout<<deque<<endl;

while(deque.size() > 0)
cout<<deque.removeLast();

分析 Queue 和 Priority Queue 的源码
#queue:
Queue<string> queue = new LinkedList<string>();
queue.offer("one")
queue.poll()
queue.peek()
queue.size()
#Priority Queue

删除排序数组中的重复项（Facebook、字节跳动、微软在半年内面试中考过）
class Solution {
public : int removeDuplicates(vector<int>& nums) {
    if(nums.empty()) return 0;
    if(nums.size()==1) return 1;
        int j=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[j]){
                j++;
                nums[j]=nums[i];
            }
        }
         return (j+1);
    }
};
旋转数组（微软、亚马逊、PayPal 在半年内面试中考过）

合并两个有序链表（亚马逊、字节跳动在半年内面试常考）

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* preHead=new ListNode(-1);
        ListNode* prev=preHead;
        while(l1!=nullptr && l2!=nullptr){
            if(l1->val < l2->val){
                prev->next=l1;
                l1=l1->next;
            }else{
                prev->next=l2;
                l2=l2->next;
            }
            prev=prev->next;
        }
        prev->next= l1==nullptr ? l2 : l1;
        return preHead->next;
    }
};

-----
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr){
            return l2;
        }
        if (l2 == nullptr){
            return l1;
        }
        if(l1->val <= l2->val){
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        }
        l2->next=mergeTwoLists(l2->next,l1);
        return l2;
    }
};
-----
合并两个有序数组（Facebook 在半年内面试常考）

两数之和（亚马逊、字节跳动、谷歌、Facebook、苹果、微软在半年内面试中高频常考）
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> tar;
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
-----
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

移动零（Facebook、亚马逊、苹果在半年内面试中考过）
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] != 0){
                nums[j] = nums[i];
                if(i !=j){
                    nums[i]=0;
                }
                j++;
            }
        }
    }
};
加一（谷歌、字节跳动、Facebook 在半年内面试中考过）
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1;i>=0;i--){
            digits[i]++;
            digits[i]=digits[i]%10;
            if(digits[i]!=0)
            return digits;
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};

# 中等： #
设计循环双端队列（Facebook 在 1 年内面试中考过）

# 困难： #
接雨水（亚马逊、字节跳动、高盛集团、Facebook 在半年内面试常考）