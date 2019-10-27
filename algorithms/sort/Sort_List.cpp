/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // method 1, 把链表转化为数组，然后对数组排序，同时保存原来索引位置，然后再遍历一遍链表，根据数组进行赋值
    // 但该方法的问题在于空间复杂度为o(2*n)，不满足题目的性能条件
    
    // method 2, 归并排序，由于是o(1)的空间复杂度要求，所以不用递归，采用循环
    // 归并排序的本质是不同元素数的两个有序列表的迭代合并，第一次,元素数为1合并后为2，第二次,元素数为2合并后为4，....，第(N + 1 / 2)次合并后即结束
    // 时间复杂度o(n*logn), 空间复杂度为o(1)
    // 返回链表长度
    int get_sum(ListNode* head){
        int sum = 0;
        ListNode* tmp = head;
        while (tmp){
            sum++;
            tmp = tmp->next;
        }
        return sum;
    }
    

    ListNode* merge_sort(ListNode* tmp, int step){
        // NOTE 1, initialize ListNode method, 
        ListNode* head = new ListNode(0);
        // NOTE 2, 对链表节点指针变量的操作，有些方式可以改变值，有些不能改变
        // right = root; // 不能改变函数外部right的值， right->val输出2
        // right->val = 10; // 可以改变函数外部right的值，right->val输出10
        // right->next = root; // 可以改变函数外部right->next的值，right->next->val输出0
        // 链表的归并排序
        head->next = tmp;
        ListNode* root = head; 
        ListNode* left = NULL;
        ListNode* right = NULL;       

        while (tmp){
            int left_num = 0;
            int right_num = 0;
            // 两两归并，找到两个待归并子链表的头部
            left = tmp;          
            while(left_num < step && tmp){
                left_num ++;
                tmp = tmp->next;
            }
            // 1，左右子链表长度都等于step，正常合并
            // 2，无右子链表，分为两种子情况，左子链表长度为step，左子链表长度小于step，两种子情况，不用合并 
            right = tmp;
            if (right == NULL){
                // NOTE 3， 如果只有左子链表，没有右子链表，一定记得把左子链表添加到结果中
                head->next = left;
                break;
            }
            // 3,  左子链表长度等于step，右子链表长度小于step
            while (right_num < step && tmp){
                right_num++;
                tmp = tmp->next;
            }
            while (left_num || right_num){
                while (left_num && (right_num == 0 || left->val < right->val)){
                    head->next = left;
                    head = head->next;
                    // NOTE 4， 断开节点，否则可能造成死循环
                    left_num--;
                    if (left_num == 0){
                        left->next = NULL;
                        break;
                    }
                    left = left->next;
                }
                // NOTE 5, right_num 先判断，避免对NULL取值, 其次left_num也要先判断，防止对NULL取值
                while(right_num && (left_num == 0 || left->val >= right->val)){  
                    head->next = right;
                    head = head->next;
                    right_num --;
                    if (right_num == 0){
                        right->next = NULL;
                        break;
                    }
                    right = right->next;         
                }       
            }       
        }
        // NOTE 6, 构造假头节点，再返回头结点的next
        return root->next;
    }
    ListNode* sortList(ListNode* head) {
        // 处理特例
        if (head == NULL || head->next == NULL)return head;
        // 1，先计算出链表一共多少个节点
        int sum = get_sum(head);
        // NOTE 7，一共合并(sum+1)/2次数,判断条件是step <= sum，不是step<sum
        for (size_t step = 1; step <= sum; step*=2){
            head = merge_sort(head, step);
            ListNode* tmp = head;            
        }
        return head;
    }
};
