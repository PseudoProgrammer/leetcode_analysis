class Solution {
public:
    // // method 1，动态规划，时间复杂度o(n*n)，空间复杂度o(n)
    // // 动态方程是dp[n + 1] = dp[n](if nums[n] <= max) or dp[n] + 1(if nums[n] > max)
    // // 状态定义：自变量为nums的索引n，应变量是以nums[n]作为子序列的尾部元素条件下（这个限定条件很重要）
    // // 所能构建的最长上升子序列长度，注意这里应变量并不是0~n的数组对应的最大上升子序列长度，所以最终结果是dp数组最大值元素
    // // 初始状态：初始为1，因为nums[0] > INT_MIN，所以dp[0] = 1;
    // int lengthOfLIS(vector<int>& nums) {
    //     // 处理特殊case
    //     int max_len = 0;
    //     if (nums.size() == 0)return 0;
    //     vector<int> dp(nums.size(), 1);
    //     for (size_t i = 0; i < nums.size(); ++i){
    //         // 如果nums[i] > max，则把nums[i]添加到上一个最长上升子序列之后，成为新的最长上升子序列
    //         for (size_t j = 0; j < i; ++j){
    //             // NOTE 1(important), 动态规划的动态方程的等号右边可以是无数个变量
    //             // 即dp[n + 1] = f(dp[0], d[1],...,  dp[n]) 
    //             if (nums[j] < nums[i])dp[i] = max(dp[i], dp[j] + 1);
    //             // NOTE 2，这里不要写下面一句话，因为动态方程的限定条件是以nums[i]结尾的最长上升子序列
    //             //else dp[i] = max(dp[i], dp[j]);
    //         }
    //         max_len = max_len > dp[i]? max_len: dp[i];
    //     }
    //     return max_len;
    // }
    
    // method 2, 动态规划 + 二分搜索，时间复杂度o(n*logn)，空间复杂度o(n)
    // 第一种方法的时间复杂度较高，方法二的时间复杂度更低，两者的差别在于遍历每一个动态方程时的时间复杂度可以从o(n)->o(logn)
    // 1，状态，采用tail数组来存储，自变量是当前nums子数组的最大上升子序列长度len - 1
    // 应变量是对应的长度为len - 1的上升子序列（存在多个）的尾部元素的最小值
    // 2，动态方程if (nums[i]>tail[-1])tail.push_back[nums[i]];
    // else tail[j] = nums[i] where j is the index of first element > nums[i] 
    // 2，构造一个新的数据结构，以便存储历史元素大小关系，即tail数组，包含两部分，下标，value。
    // 下标是是当前nums子数组的最大上升子序列长度len，value是对应的长度为len的上升子序列（存在多个）的尾部元素的最小值
    // 更新tail数组的法是：比较nums[i]和tail数组，采用二分搜索法，按照从左到右的顺序，找到tail数组中tail[j]
    // tail[j]是第一个大于nums[i]的元素
    // 分为两种情况，A，如果能找到，更新历史的最长上升子序列长度==j对应的尾部元素，即tail[j] = nums[i]
    // B，如果不能找到，更新当前的最长上升子序列，即tail.push_back[nums[i]]
    // 3，tail数组的长度即为最大上升子序列长度
    // 4, 初始状态
    
    // 4, 可以思考一下为什么要采用二分搜索法，按照从左到右的顺序，替换tail[j]（第一个大于nums[i]） = nums[i]？这是问题的关键
    // 事实上，这是为了满足动态方程的应变量是对应的长度为len的上升子序列（存在多个）的尾部元素的最小值，因为
    // A，tail[0]到tail[j - 1]的值（即长度为1到j的上升子序列的尾部元素值）都比nums[i]小，所以不用更新尾部元素
    // B，tail[j + 1]到tail[-1]的尾部元素如果用nums[i]来更新，会使得对应序列不再是上升子序列
    // C, tail[j]对应了长度为j+1的上升子序列的尾部元素值为tail[j]，而nums[i]>tail[j-1] && nums[i] < tail[j]，所以新的上升子序列（tail[j - 1]对应的上升子序列，拼接上nums[i]）才是尾部元素最小的长度为j+1的上升子序列
    int binary_search(const vector<int>& tail, int val){
        // 返回第一个大于val的元素对应的索引index
        int i = 0;
        int j = tail.size() - 1;
        int m;
        if (tail[0] > val)return 0;
        while (i <= j){
            m = (i + j) / 2;
            // NOTE 1, 一定注意了，这里i=m+1,而不是i=m，否则容易陷入死循环
            if (tail[m] < val)i = m + 1;
            else if (tail[m] > val)j = m - 1;
            // 如果存在相等的元素索引
            else return m;
        }
        // 如果不存在相等的元素，返回第一个更大的元素索引,这里不确定是tail[m]还是tail[m+1]第一个大于val，所以比较一次
        if (tail[m] > val)return m;
        else return m + 1;
    }
    int lengthOfLIS(vector<int>& nums) {
        // 处理特殊case
        //nums.resize(2,2);
        if (nums.size() == 0)return 0;
        // 初始化动态方程存储结构
        vector<int> tail(1, nums[0]);
        for (size_t i = 1; i < nums.size(); ++i){
            // 大于，则当前最长上升子序列加1
            if (nums[i] > tail[tail.size() - 1])tail.push_back(nums[i]);
            // 不大于（由于题意说了不重复，不存在等于情况），则更新历史某一个最长上升子序列的尾部元素
            int index = binary_search(tail, nums[i]);
            tail[index] = nums[i];
        }
        return tail.size();
    }
};
