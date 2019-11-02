class Solution {
public:
    // method 1， 排序算法, 时间复杂度o(n*logn), 空间复杂度o(1)
    // 什么排序算法都可以，这里特别地，采用堆排序，平时堆排序的场景少，刚好演练一下
    // 1, 堆排序，原地正排序
    // 2, 从小到大开始遍历数组size N，直到找到一个元素位置index， 第一次出现N-index<citations[index],则N-index就是h指数了
    
    // method 2, 堆排序+早停, 时间复杂度o(n*logn), 空间复杂度o(1),但比method 1更快一些
    // 采用堆排序算法对citations排倒序，从大到小一直迭代更新数组尾部元素，直到第一次出现N-index<citations[index]，则N-index
    
    // 互换元素
    void swap(vector<int>& citations, int k, int i){
        int tmp = citations[k];
        citations[k] = citations[i];
        citations[i] = tmp;
    }
    
    // 从上往下更新子树，根节点为k，尾端为end
    void to_down(vector<int>& citations, int k, int end){
       int index;
        // NOTE 5, 索引是<= end，不是< end
       while (2 * k + 1 <= end){
           index = 2 * k + 1;
           if (index + 1 <= end && citations[index] < citations[index + 1])index ++;
           if (citations[index] > citations[k]){
               swap(citations, index, k);
               k = index;
           }else break;
       }
    }
    
    // 从底向上更新
    void to_top(vector<int>& citations){
        // NOTE 1, 第一个非叶子节点的索引是citations.size() / 2 - 1，但只能保证有左孩子节点
        for (int i = citations.size() / 2 - 1; i >= 0; --i){
            // 初始化交换的孩子节点索引
            int k = 2 * i + 1;
            // 比较左右孩子节点大小
            // NOTE 2, 判断是有右孩子节点，防止k+1数组越界
            if (k + 1 < citations.size() && citations[k] < citations[k + 1])k += 1;
            // 比较父节点和孩子节点大小
            if (citations[k] > citations[i]){
                swap(citations, k, i);
                to_down(citations, k, citations.size() - 1);
            }    
        }
    }
    
    // 构建大顶堆，堆的初始化
    void init_heap(vector<int>& citations){
        to_top(citations);
    }
    
    void update_heap(vector<int>& citations, int end){
        // 先把堆顶元素放到数组尾端
        // NOTE 5, 索引是end
        swap(citations, 0, end);
        // 从上到下更新堆
        // NOTE 5, 索引是end - 1
        to_down(citations, 0, end - 1);
    }
    
    int hIndex(vector<int>& citations) {
        init_heap(citations);
        // NOTE 2, j >=0, 不是j>0,避免输入为[1], 输出为0
        int res = 0;
        for (int j = citations.size() - 1; j >= 0; --j){
            // NOTE 5, 索引是j
            update_heap(citations, j);
            int nums = citations.size() - j;
            // NOTE 3, 注意返回条件，每次更新h-index，直到citations[j] < nums跳出循环
            if (citations[j] >= nums)res = nums;
            else return res;
        }
        return res;
    }
};
