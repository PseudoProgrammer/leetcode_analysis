class Solution {
public:
    // method 1, 动态规划，用空间换时间，采用i*j的二维数组记录index从[i,j]的连续子数组大小
    // 每次都对连续子数组的长度加1，动态转移方程为f(i, j+1) = f(i, j) + nums[j+1]，f(i-1, j) = f(i, j) + nums[i-1];
    // 时间复杂度o（n*n），空间复杂度o（n*n）
    
    // method 2，动态规划，难点在于从哪个维度去构建最优子结构
    // 注意题目中指出是连续子数组，因而可以定义这样的一个最优结构，全子数组，左子数组，右数（一个数），左子数组+右数=全子数组
    // 全子数组最优（取最大值）时，左子数组是最优（不存在比改子数组）的左子数组，即包含左子数组左边元素的所有数组的序列和都小于0
    
    int maxSubArray(vector<int>& nums){
        int sum = 0;
        int max = INT_MIN;
        for (size_t i = 0; i < nums.size(); ++i){
            sum += nums[i];
            // NOTE 1， 注意下面两行代码顺序不能反转，否则输入[-1]，输出0，不符合预期
            if (sum > max)max = sum;
            if (sum < 0)sum = 0;    
        }
        return max;
    }
};
