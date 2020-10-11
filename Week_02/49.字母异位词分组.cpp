/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> work;//字符串与下标的对应关系
        int sub = 0;//结果vector的下标
        for(auto str:strs){
            string tmp = str; //临时string,并排序
            sort(tmp.begin(), tmp.end());
            if(work.count(tmp)){ //hashmap中查找排序后的字符串的数量
                //work[tmp]是下标
                res[work[tmp]].push_back(str);
            }else{//如果没有，新建一个
                //构造一个元素个数为1，值为str的vector
                vector<string> vec(1, str); 
                res.push_back(vec);
                work[tmp]=sub++;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res; //存储结果
        unordered_map<string,vector<string>> m; //定义一个映射
        for(string &s : strs){ //遍历strs
            string t = s; //定义一个临时存储，并排序
            sort(t.begin(), t.end());
            m[t].push_back(s);
            //t为单词的按顺序排列，作为Key值
            //m[t]则为该单词的异位词构成的vector,作为value值
        }
        for(auto& n : m){ //n为键和值组成的pair
            res.push_back(n.second);
        }
        return res;
    }
};


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<double, vector<string>> m;
        double a[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
        for(string & s : strs){
            double t = 1;
            for(char c : s){
                t *= a[c - 'a'];
            }
            m[t].push_back(s); //t为单词对应的质数乘积，m[t]则为该单词的异位词构成的vector
        }
        for(auto & n : m){
            res.push_back(n.second);
        }
        return res;
    }
};*/
// @lc code=end

