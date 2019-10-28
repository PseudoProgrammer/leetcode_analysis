class Solution {
public:
    // method 1，暴力解法，从1到num遍历i，如果num / i == i && num % i == 0则迭代截止
    // 时间复杂度o(n)，空间复杂度o(1) 
    
    // method 2, 二分查找，由于查找的代码是从1->num，解集是有序的，因而可以用二分查找来确定
    // 时间复杂度o(log n), 空间复杂度o(1)
    bool isPerfectSquare(int num) {
        // 0, 处理特殊case
        if (num == 1)return true;
        // 1，初始化双指针
        int i = 1;
        // NOTE 1, 为了防止下面 (i + j) / 2对int范围越界，j != num，不影响结果
        int j = num - 1;
        // 2，迭代查找
        int mid;
        int div;
        // NOTE 2, 为了防止死循环，不要写j > i, 比如num == 14的情况下，i，j会为3，4，一直跳不出while循环
        while (j > i + 1) {
            mid = (i + j) / 2;
            div = num / mid;
            if (div > mid)i = mid;
            else if (div < mid)j = mid;
            else if (num % mid != 0)i= mid;
            // div == mid && num % mid == 0则mid * mid = num
            else return true;
        }
        // 3，未找到，返回false
        return false;
    }
};
