class Solution {
public:
    // method 1，动态规划，非递归
    // 首先，该题明显需要做很多重复计算
    // 其次，可以分析出最优子结构，即动态方程为函数映射，以和为自变量，以和的组合的个数为应变量。
    // dp(sum) = sum([i for i in nums if i >=0]),
    // 其中，叶子节点的值，dp[0] = 1, dp[负数]=0;主要因为数组和target都是正整数，非正整数不能这样初始化叶子节点的值
    int combinationSum4(vector<int>& nums, int target) {
        // 异常输入
        assert(target > 0);
        // NOTE 1， 一定要存储double，否则int可能会溢出。比如输入为[3, 33, 333]，10000
        // 定义动态方程存储结构
        vector<int> dp;
        // 初始化叶子节点的值
        dp.push_back(1);
        // 遍历动态方程的自变量
        for (size_t sum = 1; sum <= target; sum ++){
            int n = 0;
            for (size_t i = 0; i < nums.size(); ++i){
                int diff = sum - nums[i];
                if (diff < dp.size() && diff >=0){
                    double add = double(n) + dp[diff];
                    // 由于返回值为int，因而按照题意不可能超过int类型，所以这里做个阈值截断
                    if (add > INT_MAX)n = INT_MAX;
                    else n += dp[diff];
                }
            }
            dp.push_back(n);
        }
        return dp[target];
    }
};
