class Solution {
public:
//     // 贪婪算法常用的解法是借助for、while、递归三种方式实现
    
//     // method 1, 递归解法，在t中先找到s的首字母，然后分解为两个子问题：s的剩余字母在t的剩余字母中；s在t的剩余字母中，两者一个true则为true
//     // 时间复杂度是o(len(t)^len(s))，空间复杂度是o(1)
//     // 使用&引用传递，节省内存，用户内存消耗性能，击败5%->击败52%
//     bool isSub(string & s, int s_start, string &t, int t_start){
//         // 处理异常case，当s的长度为0时返回真
//         if (s.size() - s_start == 0)return true;
//         // 递归解法
//         for (int i = t_start; i < t.size(); ++i){
//             if (s[s_start] == t[i])return isSub(s, s_start + 1, t, i + 1) || isSub(s, s_start, t, i + 1);
//         }
//         return false;
//     }
    
//     bool isSubsequence(string s, string t) {
//         if (isSub(s, 0, t, 0))return true;
//         else return false;
//     }
    
    // method 2，非递归解法，（也可用多指针解法，采用s.size()个数的下标来进行多指针寻址，但该题不用这么麻烦，如果该题是判断连续子串的话可以用多指针）
    bool isSubsequence(string s, string t){
        // 处理特殊case
        if (s.size() == 0)return true;
        // 处理一般case
        vector<int> ind;
        // 初始化多指针
        ind.resize(s.size(), 0);
        // 这里有个技巧是，不用关注t是否有重复元素，比如abc是adcbec的子序列，adcbec出现两次c并不会影响我们的代码编写
        // 因而外层用for循环，不用while
        // start初始化为-1，会节省while循环内start++，节省代码量
        int start = - 1;
        int end = t.size();
        for (size_t i = 0; i < s.size(); ++i){
            // NOTE 1，这里一定不能用start < t.size()，因为start为int，t.size()为size_t，start=-1，t.size()=6时，start< t.size()为假
            while (start < end){
                // 别忘了start++，否则s中包含重复字母就可能会出错
                start++;
                // 加上这句话判断，防止下一句代码start下标出界。同时，出界表示不是子序列
                if (t.size() == start)return false;
                if (t[start] == s[i])break;
            }
        }
        return true;
    }
};
