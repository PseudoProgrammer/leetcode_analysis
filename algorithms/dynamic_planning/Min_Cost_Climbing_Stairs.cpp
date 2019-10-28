class Solution {
public:
    // method 1, 暴力法，遍历所有爬楼梯的方式，找出代价最低的方式
    
    // // method 2, 递归版本，
    // // NOTE 1，新起一个函数，是为了增加end参数，也注意cost的引用，减少内存使用率
    // // NOTE 2, 这里很容易有一个误区或者歧义，认为数组最后一个元素就是最后一个阶梯了，但并不是
    // // 数组最后一个元素的右边才是楼层顶部，也就是说，楼顶在cost数组之外
    // // NOTE 3，这种方式存在重复计算问题，超出时间限制，因此动态规划的精髓还是在于1）动态规划方程；2）存储了中间结果，避免重复计算
    // int dynamic_plan(vector<int>& cost, int end){
    //     // 1，根节点返回
    //     if (end <= 1)return 0;
    //     // 2, 非根节点，递归
    //     // 从倒数第1个跳上来   
    //     int left = cost[end - 1] + dynamic_plan(cost, end - 1);
    //     // 从倒数第2个跳上来
    //     int right = cost[end - 2] + dynamic_plan(cost, end - 2);
    //     if (left > right)return right;
    //     else return left;
    // }
    // int minCostClimbingStairs(vector<int>& cost) {
    //     // 处理异常case
    //     assert(cost.size() >= 2);
    //     return dynamic_plan(cost, cost.size());
    // }
    
    // method 3, 动态规划，非递归
    // 到达地i个阶梯的最小花费是两个花费的最小值，第1个花费是到达第i-1个阶梯的最小花费，第2个花费是到达第i-2个阶梯的最小花费
    // 即动态转移方程: mid[i] = min(mid[i - 1] + cost[i - 1], mid[i - 2] + cost[i - 2]);
    // 采用mid数组来存储达到每个阶梯的最小花费
    int minCostClimbingStairs(vector<int>& cost){
        size_t n = cost.size();
        vector<int> mid(n + 1, 0);
        for (size_t i = 2; i <= n; ++i){
            mid[i] = min(mid[i - 1] + cost[i - 1], mid[i - 2] + cost[i - 2]);
        }
        return mid[n];
    }
};
