class Solution {
public:
    // method 1，一维排序问题。粗看起来是二维排序问题，可以转化为一维排序问题
    // 二维数组展开为矩阵，大小就是n行*2列，我们把第一列做正排序
    // 然后根据排序顺序遍历二维数组的相邻两个一维数组，如果左边数组的第二个值>=右边数组的第一个值，则为重叠区域
    // NOTE 1, 二维数组是未排好序的，需要排序一次
    // 快排
    void quick_sort(vector<int>& sort_index, vector<int>& nums, int start, int end){
        // 递归的叶子节点处理
        if (end - start <= 0)return;
        // 递归的非叶子节点处理
        int i = start;
        int j = end;
        // 开始，抽离哨兵
        int base = nums[start];
        int base_index = sort_index[start];
        while (i < j){
            while (i < j && nums[j] >= base)j --;
            nums[i] = nums[j];
            sort_index[i] = sort_index[j];
            while (i < j && nums[i] <= base)i++;
            nums[j] = nums[i];
            sort_index[j] = sort_index[i];
        }
        // 收尾，放置哨兵
        nums[i] = base;
        sort_index[i] = base_index;
        // 开始递归
        quick_sort(sort_index, nums, start, i - 1);
        quick_sort(sort_index, nums, i + 1, end);
    }
    vector<int> get_sort_index(vector<vector<int>>& intervals){
        vector<int> sort_index;
        vector<int> nums;
        for (size_t i = 0; i < intervals.size(); ++i){
            nums.push_back(intervals[i][0]);
            sort_index.push_back(i);
        }
        quick_sort(sort_index, nums, 0, sort_index.size() - 1);
        return sort_index;
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        // 处理特殊case
        if (intervals.size() <= 1)return intervals;
        // 处理一般case
        vector<int> sort_index = get_sort_index(intervals);
        for (size_t j = 0; j < sort_index.size() - 1; ++j){
            // 两个一维数组比大小，有三种情况
            // 1, 不重叠，输出
            int i = sort_index[j];
            int i_next = sort_index[j + 1];
            if (intervals[i][1] < intervals[i_next][0])res.push_back(intervals[i]);
            else {
                // 2, 重叠，交叉关系
                intervals[i_next][0] = intervals[i][0];
                // 3, 重叠，包含关系，左边数组包含右边数组
                if (intervals[i][1] > intervals[i_next][1])intervals[i_next][1] = intervals[i][1];
            }       
        }
        int last = sort_index[sort_index.size() - 1];
        res.push_back(intervals[last]);
        return res;
    }
};
