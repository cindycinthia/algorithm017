/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
/*
*1.排序，时间复杂度o(nlogn) 空间o(1)
*2.
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end()); //排序 判断是否相等
        sort(t.begin(), t.end());
        return s == t;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false; //如果size不等，直接返回false
        unordered_map<char, int> map; //定义一个hashmap，将s加入hashmap
        for(char c : s) map[c] ++; 
        for(char c : t)   //如果map[]--等于-1 ，说明不符合
            if(-- map[c] == -1) return false;
        return true;
    }
};


class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;
        //if(s.size() != t.size()) return false;可以加这一句，排除掉长度不一致的情况
        //小于俩个中大的size,否则是false的情况会无法判别，如a,ab
        for(int i = 0; i < max(s.size(), t.size()); i ++) 
            map[s[i]] ++, map[t[i]] --;
        for(auto it : map)  //it.second为哈希表的value
        //遍历哈希表,如果有不为0的value存在，返回false
            if(it.second != 0) return false;
        return true;
    }
};
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int hash[26] = {0};  //用一个数组存储
        for(char c : s) hash[c - 'a'] ++; //先加加，后减减 ，如果出现-1，返回false
        for(char c : t) 
            if(-- hash[c - 'a'] == -1) return false;
        return true;

    }
};
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int hash[26] = {0};
        for(int i = 0; i < s.size(); i ++)  //一边加，一边减，如果出现不为0，返回false
            hash[s[i] - 'a'] ++, hash[t[i] - 'a'] --;
        for(int i = 0; i < 26; i ++) 
            if(hash[i] != 0) return false;
        return true;

    }
};


// @lc code=end

