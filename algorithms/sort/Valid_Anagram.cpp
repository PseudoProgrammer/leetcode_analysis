class Solution {
public:
    // method 1，排序解法，主要思路是先将s和t进行字符排序(使用快排)，再做字符串相等性判断，相等则是字母异位词，否则不是
    // 快排，正序
//     void quick_sort(char* str_list, int start, int end){
//         // NOTE 1, 一定记得加下面这一句，否则无限循环出字符数组的索引边界了
//         if (end - start <= 0)return;
//         // 先安排好哨兵
//         char temp = str_list[start];
//         // 进行一遍扫描
//         int i = start;
//         int j = end;
//         while (i < j){
//             // 一定要先移动右指针
//             while (i < j && str_list[j] >= temp){
//                 j --;
//             }
//             str_list[i] = str_list[j];
//             // 然后再移动左指针
//             while (i < j && str_list[i] <= temp){
//                 i ++;
//             }
//             str_list[j] = str_list[i];
//         }
//         str_list[i] = temp;
//         quick_sort(str_list, start, i - 1);
//         quick_sort(str_list, i + 1, end);
//     }
//     // 字符串转化为字符数组，便于后续排序操作
//     void convert_arr(char* str_list, string str){
//         for (size_t i = 0; i < str.size(); ++i)str_list[i] = str[i];
//     }
    
//     bool isAnagram(string s, string t) {
//         if (s.size() != t.size())return false;
//         else if(s.size() == 0)return true;
//         char s_str[s.size()];
//         char t_str[t.size()];      
//         convert_arr(s_str, s);
//         convert_arr(t_str, t);
        
//         quick_sort(s_str, 0, s.size() - 1);
//         quick_sort(t_str, 0, t.size() - 1);
//         // 比较排序后的字符串列表是否相等
//         for (int i = 0; i < s.size(); ++i){
//             // 不等则返回false
//             // cout << "s "<< s_str[i]<<", t "<<t_str[i]<<endl;
//             if (s_str[i] != t_str[i])return false;
//         }
//         // 相等则返回ture
//         // NOTE 1, c++中""是字符串，''是字符，比如char b[5], b[0] = "a" raise error, b[0] = 'a' will be right
//         return true;
//    }
    
    // method 2, 非排序解法，遍历字符串s和t，存储两个字典，对比两个字典kv是否相同，时间复杂度o(n)，空间复杂度o(1)
    // 字符串转化为词频的map
    map<char, int> get_count(const string& str){
        map<char, int> count;
        for (size_t i = 0; i < str.size(); ++i){
            if (count.find(str[i]) != count.end())count[str[i]] = count[str[i]] + 1;
            else count[str[i]] = 1; 
        }
        return count;
    }
    // 判断两个map是否相等
    // NOTE 1, use const to avoid modifying value, use & to make memory less
    bool equal_map(const map<char, int>& map_s, const map<char, int>& map_t){
        if (map_s.size() != map_t.size())return false;
        for (map<char, int>::const_iterator it = map_s.begin(); it != map_s.end(); ++it){
            // NOTE 2, we can't use auto itt = map_t.find(it->first), or can't use itt->first
            // NOTE 3, please const_iterator to replace iterator
            map<char, int>::const_iterator itt = map_t.find(it->first);
            if (itt == map_t.end() || itt->second != it->second)return false;
        }
        return true;
    }
      
    bool isAnagram(string s, string t){
        // 初始化两个字典
        map<char, int> map_s;
        map<char, int> map_t;
        map_s = get_count(s);
        map_t = get_count(t);
        if (equal_map(map_s, map_t))return true;
        else return false;
    }
    // method 3, 非排序解法，和method 2的唯一区别在于，不用两个map来存储词频，只用一个map来存储字符串s
    // 然后遍历字符串t，每个字符都使得map对应key的频次减1，空间复杂度减半
    // 和method 2实现差不多，这里不再写出
};
