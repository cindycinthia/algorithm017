1.排序 时间复杂度nlogn
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> vec(k, 0);
        sort(arr.begin(), arr.end());
        for (int i = 0; i < k; ++i) {
            vec[i] = arr[i];
        }
        return vec;
    }
};

2.堆 
//时间复杂度：O(nlogk)
队列那么先要包含头文件#include <queue>
优先队列具有队列的所有特性，包括基本操作，只是在这基础上添加了内部的一个排序，它本质是一个堆实现的
top 访问队头元素
empty 队列是否为空
size 返回队列内元素个数
push 插入元素到队尾 (并排序) //大顶堆插入后自动维护排序
emplace 原地构造一个元素并插入队列
pop 弹出队头元素
swap 交换内容
定义：priority_queue<Type, Container, Functional>
Type 就是数据类型，Container 就是容器类型（Container必须是用数组实现的容器，比如vector,deque等等，但不能用 list。
STL里面默认用的是vector），Functional 就是比较的方式，当需要用自定义的数据类型时才需要传入这三个参数，
使用基本数据类型时，只需要传入数据类型，默认是大顶堆
//升序队列
priority_queue <int,vector<int>,greater<int> > q;
//降序队列 ,大顶堆
priority_queue <int,vector<int>,less<int> >q;

pari的比较，先比较第一个元素，第一个相等比较第二个
class Solution{
    public:
    vector<int> getLeastNumbers(vector<int>& arr,  int k){
        vector<int> vec(k, 0);
        if(k == 0){
            return vec;
        }
        priority_queue<int> heap;  //对于基础类型 默认是大顶堆,等同于 priority_queue<int, vector<int>, less<int> > a;
        for(int i = 0; i < k; ++i){//将前 k个数插入大根堆中
            heap.push(arr[i]);
        }
        for(int i = k; i < (int)arr.size(); ++i){   //从第 k+1 个数开始遍历
            if(heap.top() > arr[i]){  //如果当前遍历到的数比大根堆的堆顶的数要小
                heap.pop();    //就把堆顶的数弹出，再插入当前遍历到的数
                heap.push(arr[i]);
            }
        }
        for(int i = 0; i < k; ++i){  //最后将大根堆里的数存入数组返回即可
            vec[i] = heap.top();
            heap.pop();
        }
        return vec;
    }
};

class Solution{
    public:
    vector<int> getLeastNumbers(vector<int>& arr,  int k){
        vector<int> res;
        if(k > arr.size()) return res;
        //大根堆
        priority_queue<int> heap;
        //找到最小的K个数字
        for(auto x : arr){
            //if(heap.size() < k || heap.top() > x) //优先队列自动维护了
            heap.push(x);
            if(heap.size() > k) heap.pop();
        }
        //
        while(heap.size()){
        res.push_back(heap.top()), heap.pop();
        }
        //reverse(res.begin(), res.end());
        return res;
    }
};


3.快排
class Solution {
    int partition(vector<int>& nums, int l, int r) {
        int pivot = nums[r];
        int i = l - 1;
        for (int j = l; j <= r - 1; ++j) {
            if (nums[j] <= pivot) {
                i = i + 1;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[r]);
        return i + 1;
    }
    // 基于随机的划分
    int randomized_partition(vector<int>& nums, int l, int r) {
        int i = rand() % (r - l + 1) + l;
        swap(nums[r], nums[i]);
        return partition(nums, l, r);
    }
    void randomized_selected(vector<int>& arr, int l, int r, int k) {
        if (l >= r) {
            return;
        }
        int pos = randomized_partition(arr, l, r);
        int num = pos - l + 1;
        if (k == num) {
            return;
        } else if (k < num) {
            randomized_selected(arr, l, pos - 1, k);
        } else {
            randomized_selected(arr, pos + 1, r, k - num);
        }
    }
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        srand((unsigned)time(NULL));
        randomized_selected(arr, 0, (int)arr.size() - 1, k);
        vector<int> vec;
        for (int i = 0; i < k; ++i) {
            vec.push_back(arr[i]);
        }
        return vec;
    }
};


