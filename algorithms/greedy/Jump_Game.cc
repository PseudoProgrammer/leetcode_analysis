class Solution {
public:
    // 分析题意
    // 首先读懂题意，每个位置都可以跳跃，题目没有说明只能向右跳，所以向左跳和向右跳都是可以的。但向左跳会增加我们搜索的复杂度
    // 思考向左跳有意义吗？向左跳没有意义，可以剪枝
    // 反证法，加入向左跳一次才能到达终点。那么在当前状态A向左跳一次到B，也是相当于在到达当前状态之前的所有状态直接跳到B
    // 主要是因为起点是0，既然能调到更远的位置A，那么也能调到更近的位置B
    
// method 1, 因而可以用递归方法，每次向右跳, 但会超出时间限制错误
//     bool canRightJump(vector<int>& nums, int now){
//         // 处理特殊case, 已经到达终点，返回真
//         if (nums.size() - now == 1)return true;
//         // 至少跳一步
//         for (int i = 1; i <= nums[now]; ++i){
//             // 不能超出界限
//             if (now + i >= nums.size())continue;
//             // 处理一般情况
//             if (canRightJump(nums, now + i))return true;
//         }
//         return false;  
//     }
    
//     bool canJump(vector<int>& nums) {
//         // 处理异常case
//         assert(nums.size() >= 1);
//         // 调用递归函数，初始位置为0
//         if (canRightJump(nums, 0))return true;
//         else return false;
//     }
    // method 2, 利用推理将问题做一个简化，等价转化为另一个小问题，问题可以转化为是否能跳过所有的值为0的元素
    // 根据题意，所有元素都是非负整数，两种可能，正整数和0。
    // 如果所有元素都是正整数，那么显然可以跳到终点
    // 如果出现为0的元素，那么只要能跳过这个0就可以，采用for循环来遍历所有位置，采用while循环了来判断是否能跳过0
    bool canJump(vector<int>& nums){
        // 处理异常
        assert(nums.size() >= 1);
        // NOTE 1, 39和41行代码的顺序不能调换
        // 起点即终点，返回真
        if (nums.size() == 1)return true;
        // 处理特殊情况，第一个位置为0，则永远跳不到终点
        if (nums[0] == 0)return false;
        // 注意，终点不用判断是否能跳过去，只判断是否能跳过终点前一站就好了
        for (int i = 1; i < nums.size() - 1; ++i){
            // 非0则继续查找0元素
            if (nums[i] != 0)continue;
            // 如果是0元素,则往回找看那个位置开始起跳，可以跳过这个0
            int j = i - 1;
            while (j >= 0){
                // <则表示能跳过
                if (i - j < nums[j])break;
                j--;
            }
            if (i != 0 && j == -1)return false;
        }
        // 如果遍历结束表示跳到了终点，返回真
        return true;
    }
};
