class Solution {
public:
    // method 1, 字典记录法。遍历第一个数组，字典 value自加1，遍历第二个数组字典value自加1，遍历字典，找到value为2的所有key
    // 之所以采用字典记录法，是因为两个数组有重复元素，字典可以用于去重
    // method 2, 字典记录法。类似于method1， 遍历第二个数组时就可以直接记录输出结果，不用再把字典遍历一遍找到value为2的key了
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // 遍历第一个数组
        map<int, int> count;
        vector<int> res;
        for (size_t i = 0; i < nums1.size(); ++i){
            count[nums1[i]] = 1;
        }
        // 遍历第二个数组
        for (size_t j = 0; j < nums2.size();++j){
            map<int, int>::iterator it = count.find(nums2[j]);
            if (it != count.end() && it->second == 1){
                res.push_back(it->first);
                it->second ++;
            }
        }
        // 输出结果
        return res;
    }
};
