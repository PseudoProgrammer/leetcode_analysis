class Solution {
public:
    // method 1，排序问题，采用堆排序。对所有元素进行排序，构建大顶堆，然后取倒数第k个元素
    // 初始化堆
    void swap(vector<int>& nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    
    // 向下递归比较大小
    void to_down(vector<int>& nums, int i, int end){
        for (int max_ind = 2 * i + 1; max_ind <= end; max_ind = 2 * max_ind + 1){
            // 先比较左右孩子节点
            if (max_ind + 1 <= end && nums[max_ind + 1] > nums[max_ind])max_ind ++;
            // 再比较父节点
            if (nums[max_ind] > nums[i])swap(nums, max_ind, i); 
            // 如果父节点已经大于孩子节点，则不用再递归
            else break;
            // NOTE 1, 一定记得重置父节点
            i = max_ind;
        }  
    }
    
    void to_top(vector<int>& nums){
        int start = nums.size() / 2 - 1;
        for (int i = start; i >= 0; --i){
            to_down(nums, i, nums.size() - 1);
        }
    }
    
    void init_heap(vector<int>& nums){
        // 堆排序
        to_top(nums);
    }
    
    // 堆更新
    void update_heap(vector<int>& nums, int end){
        swap(nums, 0, end);
        to_down(nums, 0, end - 1);
    }
    int findKthLargest(vector<int>& nums, int k) {
        // 处理异常case
        assert(k >= 1 && k <= nums.size());
        // NOTE 1, 总体处理逻辑分类为三大类case
        // 1)异常case是不符合预期的输入，
        // 2)边界case是会导致主体代码出语法错误或者逻辑错误的case，边界case分段处理
        // 3)主体case是覆盖率最大的case
        
        // 初始化最大堆，原地排序
        init_heap(nums);
        // 更新最大堆,
        // NOTE 2, 注意循环的次数, 因为只要找出第k大数就可以了，所以循环次数为k次
        // NOTE 3, 同时，注意强制转换int，nums.size()返回为size_t类型，不能为负数。否则，不会报语法错误，但结果会出错
        for (int i = nums.size() - 1; i > int(nums.size()) - k - 1; --i){
            update_heap(nums, i);
        }
        return nums[nums.size() - k];
    }
    
    
//     // method 2，堆排序问题。利用前k个数构建一个大小为k的最小堆，然后用第k+1个数来更新最小堆
//     // 如果k+1个数小于最小堆堆顶元素则堆不更新，否则替换堆顶元素更新堆
    
};
