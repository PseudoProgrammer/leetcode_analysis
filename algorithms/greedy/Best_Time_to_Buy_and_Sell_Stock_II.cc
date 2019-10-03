class Solution {
public:
    // 错误示例，采用三个元素来计算峰值和波谷，总会出现很多极端case难以处理，特别是连续相等的数出现时
    // int maxProfit(vector<int>& prices) {
    //     // 转化为最优子结构问题，使用贪婪算法
    //     // 所有的连续的波峰和波谷之间的距离和
    //     // 1, 找到连续的波峰和波谷
    //     if (prices.size() <= 1)return 0;
    //     if (prices.size() == 2){
    //         if (prices[1] > prices[0])return prices[1] - prices[0];
    //         else return 0;
    //     }
    //     // 定义波峰和波谷
    //     int low = -1;
    //     int high = -1;
    //     // 定义最终结果sum
    //     int sum = 0;
    //     // 第0个节点特殊处理
    //     if (prices[1] > prices[0])low = prices[0];
    //     for(size_t l = 0; l < prices.size() - 2; ++l){
    //         size_t m = l + 1;
    //         size_t r = l + 2;
    //         // index j指向波峰
    //         // 出现第一个波谷之后，一定是先出现波谷再出现波峰，相继出现
    //         // NOTE 1, 注意左开又闭，双开不能正确处理某些特殊case，比如[2, 2, 5]
    //         if (prices[m] <= prices[l] && prices[m] < prices[r]){
    //             low = prices[m];
    //         }else if(prices[m] >= prices[l] && prices[m] > prices[r]){
    //             if(low != -1){
    //                 high = prices[m];
    //                 sum += high - low;
    //                 cout << "low is "<< low <<", high is "<< high<<", sum is "<<sum<<endl;
    //                 // 置位，否则不能处理特殊case，比如[5,5,4,9,3,8,5,5,1,6,8,3,4]，会错误把第7个元素5当成波峰
    //                 low = -1;
    //                 high = -1;
    //             }
    //         // 处理特殊情况，最后一个节点是波峰情况
    //         }
    //         if(m == prices.size() - 2 && prices[m] < prices[r]){
    //             if(low != -1){
    //                 high = prices[r];
    //                 sum += high - low;
    //             }
    //         }
    //     }
    //     return sum;
    // }
    
    int maxProfit(vector<int>& prices) {
        // 正确示例， 采用两个元素比较得出峰值和波谷
        // 转化为最优子结构问题，使用贪婪算法
        // 所有的连续的波峰和波谷之间的距离和
        // 1, 处理特殊情况
        if (prices.size() <= 1)return 0;
        // 2, 找到连续的波峰和波谷
        // NOTE 1, 不是上面的那种极值找法，不比较三个元素，只比较两个元素
        // NOTE 2, 不是上面的for循环，而是while循环，注意两者的区别，for循环是依次遍历，while是条件遍历
        int valley = prices[0];
        int peak = prices[0];
        int sum = 0;
        int i = 0;
        while (i < prices.size() - 1){         
            while (i < prices.size() - 1 && prices[i] >= prices[i + 1])i++;
            valley = prices[i];
            // 当prices= [2, 2, 5]时，5也会成为峰值，因为只有两种情况
            // 一种，倒数第二个数>=倒数第一个数, 则倒数第二个数是峰值;
            // 另一种，倒数第二个数<倒数第一个数，则while循环结束，倒数第一个数自然成为峰值
            while (i < prices.size() - 1 && prices[i] <= prices[i + 1])i++;
            peak = prices[i];
            sum += peak - valley;
        }
        return sum;
    }
};
