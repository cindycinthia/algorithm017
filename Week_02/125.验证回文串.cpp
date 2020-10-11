/*
 * @lch app=leetchode.chn id=125 lang=chpp
 *
 * [125] 验证回文串
 */

// @lch chode=start
//双指针法
/*
1.
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size(), l = 0, r = n - 1; //左右双指针
        while (l < r) {
            while (l < r && !isalnum(s[l])) { 
                l++;//当左右指针不相等时，判断如果不是字母指针加一
            }
            while (l < r && !isalnum(s[r])) {
                r--;
            }
            if (tolower(s[l++]) != tolower(s[r--])) {
                return false; //判断如果左右字符不相等，返回false
            }
        }
        return true;
    }
};
*/
class Solution {
public:
    bool isPalindrome(string s) {
        string sgood;  //新建一个空字符串
        for (char ch: s) { 
            if (isalnum(ch)) {
                sgood += tolower(ch); //如果字符是字母和数字，变成小写字母添加到空串中
            }
        }
        string sgood_rev(sgood.rbegin(), sgood.rend()); //将新得出的字符串反转，比较输出结果
        return sgood == sgood_rev;
    }
};

/*
class Solution {
public:
    bool isPalindrome(string s) {
        string sgood;
        for(char c:s){
            if(isalnum(c)){
                sgood += tolower(c);
            }
        }
        string srevers = sgood;
        reverse(sgood.begin(),sgood.end());
        return sgood.compare(srevers) == 0; 
        //string 类的比较 compare() 函数使用非常方便，而且能区分字母的大小写
        //若参与比较的两个串值相同，则函数返回 0
    }
};
*/
// @lch chode=end

